#include "s21_string.h"

int s21_sprintf(char *dest, const char *fmt, ...) {
  char temp[SIZEBUFF] = {'\0'};
  if (fmt != NULL) {
    va_list(args);

    char *str = (char *)fmt;
    va_start(args, fmt);
    while (*str) {
      // if ()
      int len = 0;
      struct fl_token s21_token = {0};
      char argToStr[SIZEBUFF] = {'\0'};
      if (*str == '%') {
        len = fooParsing(
            str + 1, args,
            &s21_token); /*парсим всё что есть после % до спецификатора */
        fooDefaultVal(&s21_token); /*в токен добавляем дефолтные значения,
                                      убираем противоречащие*/
        fooConvertArg(argToStr, args,
                      s21_token); /*конвертируем аргумент в строку*/
      } else
        argToStr[0] = *str;

      s21_strcat(temp, argToStr);
      str = str + 1 + len;
    }
    va_end(args);
  } else
    printf("sega");
  s21_strcpy(dest, temp);
  return (int)s21_strlen(dest);
}

int fooParsing(const char *str, va_list args, struct fl_token *s21_token) {
  char *strPars = (char *)str;
  int LEN = 1;
  char *strall = {" -+0#123456789.cdfsugGeExXophlL%*"};
  // if (*(str) != '%') {
  // if ((int)s21_strspn(str, strall) > 0) {
  int len = (int)s21_strcspn(
      str,
      "%cdfsugGeExXop");  // определяем количество символов до спецификатора
  LEN += len;
  if ((int)s21_strspn(str, strall) >= LEN) {
    if (*(str) != '%') {
      whatType(strPars[len], s21_token);  // определяем спецификатор

      if ((int)s21_strspn(strPars, "-+ 0#") > 0 && len > 0) {  // есть ли флаг?
        int lenFlag = whatFlag(strPars, s21_token);  // какой флаг?
        strPars += lenFlag;
        len -= lenFlag;
      }

      if ((int)s21_strcspn(strPars, "hlL") == len - 1 &&
          len > 0) {  // есть ли длина?
        len -= 1;
        whatSize(strPars[len], s21_token);  //определям длину
      }

      if (len > 0) {
        if ((int)s21_strspn(strPars, "0123456789.*") ==
            len) {  //если в оставшейся части есть только эти символы, то
          whatWidhtPrec(strPars, args, s21_token,
                        len);  // определям точность и ширину
        } else
          s21_token->error = 1;
      }
      //    strPars = str + LEN;
    } else {
      //  s21_strcat(strPars, "%");
      s21_token->prc = 1;
      //  LEN = 0;
      //  strPars = str + 1;
    }
  }
  // if (s21_token->error == 1) LEN = 0;
  return LEN;
}

void whatType(char typeSprintf, struct fl_token *s21_token) {
  if (typeSprintf == 'c')
    s21_token->c = 1;
  else if (typeSprintf == 'd')
    s21_token->d = 1;
  else if (typeSprintf == 'f')
    s21_token->f = 1;
  else if (typeSprintf == 's')
    s21_token->s = 1;
  else if (typeSprintf == 'u')
    s21_token->u = 1;
  else if (typeSprintf == 'g')
    s21_token->g = 1;
  else if (typeSprintf == 'G')
    s21_token->G = 1;
  else if (typeSprintf == 'e')
    s21_token->e = 1;
  else if (typeSprintf == 'E')
    s21_token->E = 1;
  else if (typeSprintf == 'x')
    s21_token->x = 1;
  else if (typeSprintf == 'X')
    s21_token->X = 1;
  else if (typeSprintf == 'o')
    s21_token->o = 1;
  else if (typeSprintf == 'p')
    s21_token->p = 1;
}

int whatFlag(char *flagSprintf, struct fl_token *s21_token) {
  int lenFlag = (int)s21_strspn(flagSprintf, "-+ 0#");
  for (int i = 0; i < lenFlag; i += 1) {
    if (flagSprintf[i] == ' ')
      s21_token->flSpace = 1;
    else if (flagSprintf[i] == '+')
      s21_token->flPlus = 1;
    else if (flagSprintf[i] == '-')
      s21_token->flMinus = 1;
    else if (flagSprintf[i] == '0')
      s21_token->flZero = 1;
    else if (flagSprintf[i] == '#')
      s21_token->flSharp = 1;
  }
  if (s21_token->flPlus + s21_token->flMinus + s21_token->flZero +
          s21_token->flSharp + s21_token->flSpace !=
      lenFlag)
    s21_token->error = 1;
  return lenFlag;
}

void whatSize(char flagSize, struct fl_token *s21_token) {
  if (flagSize == 'h')
    s21_token->h = 1;
  else if (flagSize == 'l')
    s21_token->l = 1;
  else if (flagSize == 'L')
    s21_token->L = 1;
}

void whatWidhtPrec(const char *str, va_list args, struct fl_token *s21_token,
                   int len) {
  int Widht = 0;
  char strNum[SIZEBUFF] = {'\0'};
  s21_strncpy(strNum, str, len);
  int dot = (int)s21_strcspn(strNum, ".");
  if (strNum[dot - 1] == '*')
    Widht = va_arg(args, int);  // s21_token->flArgW = 1;
  else
    for (int i = dot - 1; i >= 0; i -= 1) {
      Widht = ((int)strNum[i] - 48) * pow(10, dot - i - 1) + Widht;
    }
  s21_token->widht = Widht;
  if (dot < len) {
    int Prec = 0;
    s21_token->flPrec = 1;
    if (strNum[dot + 1] == '*')
      Prec = va_arg(args, int);  // s21_token->flArgPrec = 1;
    else {
      for (int i = len - 1; i > dot; i -= 1) {
        Prec = ((int)strNum[i] - 48) * pow(10, len - i - 1) + Prec;
      }
    }
    s21_token->valPrec = Prec;
  }
}

void fooConvertArg(char *DestStr, va_list args, struct fl_token s21_token) {
  char ResultStr[SIZEBUFF] = {'\0'};

  if (s21_token.prc == 1) s21_strcpy(DestStr, "%");
  if (s21_token.c == 1) {
    fooArgToC(ResultStr, args, s21_token);
    s21_strcpy(DestStr, ResultStr);
  }
  if (s21_token.s == 1) {
    fooArgToS(ResultStr, args, s21_token, 0);
    s21_strcpy(DestStr, ResultStr);
  }
  if (s21_token.d == 1 || s21_token.u == 1 || s21_token.o == 1 ||
      s21_token.X == 1 || s21_token.x == 1) {
    fooArgToDU(ResultStr, args, s21_token);
    s21_strcpy(DestStr, ResultStr);
  }
  if (s21_token.f == 1 || s21_token.e == 1 || s21_token.E == 1 ||
      s21_token.g == 1 || s21_token.G == 1) {
    fooArgToFlow(ResultStr, args, s21_token);
    s21_strcpy(DestStr, ResultStr);
  }
  if (s21_token.p == 1) {
    fooArgToPoint(ResultStr, args, s21_token);
    s21_strcpy(DestStr, ResultStr);
  }
}

char *fooArgToS(char *ResultStr, va_list args, struct fl_token s21_token,
                double Num) {
  char *temp = NULL;
  char buffer[SIZEBUFF] = {'\0'};
  temp = va_arg(args, char *);
  if (temp == NULL) temp = "(null)";
  if (isnan(Num)) temp = "nan";
  if (isinf(Num)) temp = "inf";
  s21_strcpy(buffer, temp);
  if (Num == 0) {
    if (s21_token.flPrec == 1) fooConvertWithFlPrec(buffer, s21_token);
  }
  if (s21_token.widht > 0) {
    s21_memset(ResultStr, ' ', s21_token.widht);
  }
  fooPastBufInResStrWithFL(ResultStr, buffer, s21_token);
  return ResultStr;
}

char *fooArgToC(char *ResultStr, va_list args, struct fl_token s21_token) {
  char buffer[SIZEBUFF] = {'\0'};
  buffer[0] = (char)va_arg(args, int);

  if (s21_token.widht > 0) {
    s21_memset(ResultStr, ' ', s21_token.widht);
  }
  fooPastBufInResStrWithFL(ResultStr, buffer, s21_token);
  return ResultStr;
}

char *fooArgToDU(char *ResultStr, va_list args, struct fl_token s21_token) {
  char buffer[SIZEBUFF] = {'\0'};
  if (s21_token.d == 1)
    fooSpecDWithLenToStr(
        buffer, args,
        &s21_token); /*знаковое целове в 1ю строку с учетом длины*/
  if (s21_token.u == 1 || s21_token.o == 1 || s21_token.x == 1 ||
      s21_token.X == 1)
    fooSpecUWithLenToStr(
        buffer, args,
        &s21_token); /*беззнаковое целове в 1ю строку с учетом длины*/
  if (s21_token.X == 1) {
    char *bufferUp = s21_to_upper(buffer);
    s21_strcpy(buffer, bufferUp);
    free(bufferUp);
  }
  if (s21_token.flPrec == 1)
    fooConvertWithFlPrec(
        buffer, s21_token); /*конвертируем 1ю строку с учетом точности*/
  if (s21_token.widht > 0)
    fooPasteSpaceOrZero(ResultStr,
                        s21_token); /*создаем 2ю строку с учетом ширины*/

  fooPastBufInResStrWithFL(
      ResultStr, buffer,
      s21_token); /*вставляем 1ю строку во 2ю с учетом флагов*/
  return ResultStr;
}

char *fooArgToFlow(char *ResultStr, va_list args, struct fl_token s21_token) {
  char buffer[SIZEBUFF] = {'\0'};
  long double NumFromArgs = 0;
  if (s21_token.L == 0)
    NumFromArgs = va_arg(args, double);
  else
    NumFromArgs = va_arg(args, long double);
  if (isinf(NumFromArgs)) {
    s21_strcpy(buffer, "inf");
    fooSpaceOrSign(&NumFromArgs, &s21_token);
  } else if (isnan(NumFromArgs)) {
    s21_strcpy(buffer, "nan");
    fooSpaceOrSign(&NumFromArgs, &s21_token);
  } else {
    if (s21_token.G == 1 || s21_token.g == 1) {
      fooSpecGgWithLenToStr(buffer, NumFromArgs, &s21_token);
    } else if (s21_token.f == 1) {
      fooSpecFWithLenToStr(buffer, NumFromArgs, &s21_token);

    } else if (s21_token.e == 1 || s21_token.E == 1)
      fooSpecEeWithLenToStr(buffer, NumFromArgs, &s21_token);

    if (s21_token.E == 1 || s21_token.G == 1) {
      char *bufferUp = s21_to_upper(buffer);
      s21_strcpy(buffer, bufferUp);
      free(bufferUp);
    }

    if (s21_token.flPrec == 1 && s21_token.valPrec > 0)
      fooConvertWithFlPrec(buffer, s21_token);
  }
  if (s21_token.widht > 0) fooPasteSpaceOrZero(ResultStr, s21_token);

  fooPastBufInResStrWithFL(ResultStr, buffer, s21_token);
  return ResultStr;
}

char *fooArgToPoint(char *ResultStr, va_list args, struct fl_token s21_token) {
  char buffer[SIZEBUFF] = {'\0'};
  unsigned long long int Num = (unsigned long long int)va_arg(args, void *);
  s21_strcpy(s21_token.SpaceOrSign, "0x");
  s21_token.flSpaceOrSign = 2;
  fooConvertUDecOctHexToStr(buffer, Num, 16);

  if (s21_token.flPrec == 1) fooConvertWithFlPrec(buffer, s21_token);
  if (s21_token.widht > 0) fooPasteSpaceOrZero(ResultStr, s21_token);

  fooPastBufInResStrWithFL(ResultStr, buffer, s21_token);
  return ResultStr;
}

void fooConvertWithFlPrec(char *buffer, struct fl_token s21_token) {
  int sizeBuffer = s21_strlen(buffer);
  if (s21_token.s == 1) {
    if (sizeBuffer > s21_token.valPrec) {
      for (int i = sizeBuffer - 1; i >= s21_token.valPrec; i -= 1)
        buffer[i] = '\0';
    }
  } else if (s21_token.d == 1 || s21_token.u == 1 || s21_token.o == 1 ||
             s21_token.x == 1 || s21_token.X == 1) {
    if (sizeBuffer < s21_token.valPrec) {
      char temp[SIZEBUFF] = {'\0'};
      s21_memset(temp, '0', s21_token.valPrec - sizeBuffer);
      s21_strcat(temp, buffer);
      s21_strcpy(buffer, temp);
    }
  } else if (s21_token.f == 1) {
    if (sizeBuffer < s21_token.valPrec) {
      char temp[SIZEBUFF] = {'\0'};
      s21_memset(temp, '0', s21_token.valPrec - sizeBuffer);
      s21_strcat(buffer, temp);
    }
  }
}

void fooPastBufInResStrWithFL(char *ResultStr, const char *buffer,
                              struct fl_token s21_token) {
  int flSign = 0;
  if (s21_token.SpecFloat == 1 || s21_token.SpecInt == 1)
    flSign = s21_token.flSpaceOrSign;  //нужен ли знак перед числом?
  int sizeBuffer = s21_strlen(buffer) + flSign;
  int sizeResultStr = s21_strlen(ResultStr);

  if (sizeResultStr > sizeBuffer) {  //если число вместе со знаком меньше ширины
    if (s21_token.flMinus ==
        1) {  //сдвиг влево<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<
      if (flSign != 0)
        s21_memcpy(ResultStr, s21_token.SpaceOrSign,
                   flSign); /*вставляем в начало итоговой строки знак, пробел, 0
                               или 0х*/
      for (int i = flSign; i < sizeBuffer; i += 1) {
        ResultStr[i] = buffer[i - flSign];
      }
    } else if (s21_token.flMinus ==
               0) {  //сдвиг вправо<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<
      if (flSign != 0) {
        if (s21_token.flZero == 1 &&
            s21_token.SpecFloat == 1) /*если есть флаг 0 и число не целое*/
          s21_memcpy(ResultStr, s21_token.SpaceOrSign, flSign);
        else if (s21_token.flZero == 1 && s21_token.SpecInt == 1 &&
                 s21_token.flPrec ==
                     0) /*если есть флаг 0, нет точности и число целое*/
          s21_memcpy(ResultStr, s21_token.SpaceOrSign, flSign);
        else {
          ResultStr[sizeResultStr - sizeBuffer] =
              '\0'; /*обрезаем строку, оставляем нужное кол-во 0 или пробелов*/
          s21_strcat(ResultStr,
                     s21_token.SpaceOrSign); /*вставляем в конец итоговой строки
                                                знак, пробел, 0 или 0х*/
        }
      }
      for (int i = flSign; i < sizeBuffer; i += 1) {
        ResultStr[sizeResultStr - sizeBuffer + i] = buffer[i - flSign];
      }
    }
  } else {  //если число вместе со знаком больше или равно ширины
    if (flSign != 0) s21_memcpy(ResultStr, s21_token.SpaceOrSign, flSign);
    for (int i = flSign; i < sizeBuffer; i += 1)
      ResultStr[i] = buffer[i - flSign];
  }
}

void fooSpecDWithLenToStr(char *ResultStr, va_list args,
                          struct fl_token *s21_token) {
  long int Num = va_arg(args, long int);
  if (s21_token->h == 1)
    Num = (short int)Num;
  else if (s21_token->l == 0)
    Num = (int)Num;
  if (Num < 0) {
    Num = -1 * Num;
    s21_token->flSpaceOrSign = 1;  //взводим флаг, что нужно место под знак
    s21_strcpy(s21_token->SpaceOrSign, "-");
  } else if (s21_token->flPlus == 1) {
    s21_strcpy(s21_token->SpaceOrSign, "+");
    s21_token->flSpaceOrSign = 1;  //взводим флаг, что нужно место под знак
  } else if (s21_token->flSpace == 1) {
    s21_strcpy(s21_token->SpaceOrSign, " ");
    s21_token->flSpaceOrSign = 1;  //взводим флаг, что нужно место под знак
  }
  if (s21_token->SpecInt == 1 && Num == 0 && s21_token->valPrec == 0 &&
      s21_token->flPrec == 1)
    ;  //ни чего не писать если аргумент 0 при %.d
  else
    fooConvertUDecOctHexToStr(ResultStr, Num, 10);

  //    fooConvertDecToStr(ResultStr, Num);
}

void fooSpecFWithLenToStr(char *ResultStr, long double NumFromArgs,
                          struct fl_token *s21_token) {
  long double Num = NumFromArgs;
  /*  if (s21_token->L == 0)
      Num = va_arg(args, double);
    else
      Num = va_arg(args, long double);*/

  fooSpaceOrSign(&Num, s21_token); /*
   if (Num < 0) {
     Num = -1 * Num;
     s21_token->flSpaceOrSign = 1; //взводим флаг, что нужен знак
     s21_strcpy(s21_token->SpaceOrSign, "-");
   } else if (s21_token->flPlus == 1) {
     s21_strcpy(s21_token->SpaceOrSign, "+");
     s21_token->flSpaceOrSign = 1;
   } else if (s21_token->flSpace == 1) {
     s21_strcpy(s21_token->SpaceOrSign, " ");
     s21_token->flSpaceOrSign = 1;
   }*/

  long double leftNum = 0;
  long double rightNum = 0;
  if (s21_token->valPrec == 0) {
    leftNum = round(Num);
  } else
    rightNum = modfl(Num, &leftNum);
  fooConvertUDecOctHexToStr(ResultStr, leftNum, 10);
  if (s21_token->flPrec == 1 && s21_token->valPrec > 0) {
    long double pow_rightNum = rightNum * pow(10.0, s21_token->valPrec);
    long double roundRightNum = roundl(pow_rightNum);
    //    s21_strcat(ResultStr, ".");
    char tempStr[SIZEBUFF] = {'\0'};
    if (roundRightNum == 0)
      s21_memset(tempStr, '0', s21_token->valPrec);
    else {
      fooConvertUDecOctHexToStr(tempStr, roundRightNum, 10);
      if (((int)s21_strlen(tempStr) > s21_token->valPrec)) {
        leftNum += 1;
        fooConvertUDecOctHexToStr(ResultStr, leftNum, 10);
        char tempStrZero[SIZEBUFF] = {'\0'};
        s21_memset(tempStrZero, '0', s21_token->valPrec);
        s21_strcpy(tempStr, tempStrZero);
      } else {
        while ((int)s21_strlen(tempStr) < s21_token->valPrec) {
          s21_strcat(tempStr, "0");
        }
      }
    }

    s21_strcat(ResultStr, ".");
    s21_strcat(ResultStr, tempStr);
  } else if (s21_token->flPrec == 1 && s21_token->flSharp == 1) {
    s21_strcat(ResultStr, ".");
  }
}

void fooSpecEeWithLenToStr(char *ResultStr, long double NumFromArgs,
                           struct fl_token *s21_token) {
  long double Num = NumFromArgs; /*
   if (s21_token->L == 0)
     Num = va_arg(args, double);
   else
     Num = va_arg(args, long double);*/

  fooSpaceOrSign(&Num, s21_token); /*
   if (Num < 0) {
     Num = -1 * Num;
     s21_token->flSpaceOrSign = 1; //взводим флаг, что нужен знак
     s21_strcpy(s21_token->SpaceOrSign, "-");
   } else if (s21_token->flPlus == 1) {
     s21_strcpy(s21_token->SpaceOrSign, "+");
     s21_token->flSpaceOrSign = 1;
   } else if (s21_token->flSpace == 1) {
     s21_strcpy(s21_token->SpaceOrSign, " ");
     s21_token->flSpaceOrSign = 1;
   }*/

  long double leftNum = 0;
  long double rightNum = 0;
  int p = 0;
  //
  if (Num == 0)
    ;
  else if (Num >= 1) {
    while (Num / (long double)10 >= 1) {
      Num = Num / (long double)10;
      p += 1;
    }  // while (Num / (long double)10 >= 1);
  } else {
    do {
      Num = Num * (long double)10;
      p -= 1;
    } while (Num < 1);
    Num = Num *
          pow(10.0, s21_token->valPrec); /*костыль для очень маленьких чисел*/
    Num = round(Num);
    Num = Num / pow(10.0, s21_token->valPrec);
    if (Num / (long double)10 >= 1) {
      Num = Num / (long double)10;
      p += 1;
    }
  }

  if (s21_token->valPrec == 0)
    leftNum = round(Num);
  else
    rightNum = modfl(Num, &leftNum);

  fooConvertUDecOctHexToStr(ResultStr, leftNum, 10);
  // fooConvertDecToStr(ResultStr, leftNum);
  if (s21_token->flPrec == 1 && s21_token->valPrec > 0) {
    long double pow_rightNum = rightNum * pow(10.0, s21_token->valPrec);
    long double roundRightNum = roundl(pow_rightNum);
    s21_strcat(ResultStr, ".");
    char tempStr[SIZEBUFF] = {'\0'};
    if (roundRightNum == 0)
      s21_memset(tempStr, '0', s21_token->valPrec);
    else
      fooConvertUDecOctHexToStr(tempStr, roundRightNum, 10);
    // fooConvertDecToStr(tempStr, roundRightNum);
    s21_strcat(ResultStr, tempStr);
  } else if (s21_token->flPrec == 1 && s21_token->flSharp == 1) {
    s21_strcat(ResultStr, ".");
  }
  if (p < 0) {
    s21_strcat(ResultStr, "e-");
    p = p * -1;
  } else
    s21_strcat(ResultStr, "e+");
  char temp[SIZEBUFF] = {'\0'};
  fooConvertUDecOctHexToStr(temp, p, 10);
  if (s21_strlen(temp) < 2) s21_strcat(ResultStr, "0");
  s21_strcat(ResultStr, temp);
}

void fooSpecGgWithLenToStr(char *ResultStr, long double NumFromArgs,
                           struct fl_token *s21_token) {
  long double Num = NumFromArgs; /*
   if (s21_token->L == 0)
     Num = va_arg(args, double);
   else
     Num = va_arg(args, long double);*/
  fooSpaceOrSign(&Num, s21_token);

  int p = 0;
  if (Num == 0)
    ;
  else if (Num >= 1) {
    while (Num / 10 >= 1) {
      Num = Num / 10.0;
      p += 1;
    }
  } else {
    do {
      Num = Num * 10.0;
      p -= 1;
    } while (Num < 1);
  }
  if (s21_token->valPrec > p && p >= -4) {
    if (s21_token->valPrec > 0) s21_token->valPrec = s21_token->valPrec - p - 1;
    fooSpecFWithLenToStr(ResultStr, NumFromArgs, s21_token);
  } else {
    if (s21_token->valPrec > 0) s21_token->valPrec = s21_token->valPrec - 1;
    fooSpecEeWithLenToStr(ResultStr, NumFromArgs, s21_token);
  }
  if (s21_token->flSharp == 0) {
    while ((int)s21_strcspn(ResultStr, ".") < (int)s21_strlen(ResultStr) &&
           ResultStr[(int)s21_strlen(ResultStr) - 1] == '0') {
      ResultStr[(int)s21_strlen(ResultStr) - 1] = '\0';
      if (ResultStr[(int)s21_strlen(ResultStr) - 1] == '.')
        ResultStr[(int)s21_strlen(ResultStr) - 1] = '\0';
    }
  }
}

void fooSpecUWithLenToStr(char *ResultStr, va_list args,
                          struct fl_token *s21_token) {
  unsigned long int Num = va_arg(args, unsigned long int);
  if (s21_token->h == 1)
    Num = (unsigned short int)Num;
  else if (s21_token->l == 0)
    Num = (unsigned int)Num;

  if (s21_token->SpecInt == 1 && Num == 0 && s21_token->valPrec == 0 &&
      s21_token->flPrec == 1)
    ;  //ни чего не писать если аргумент 0 при %.o или %.u
  else {
    int base = 10;
    if (s21_token->o == 1)
      base = 8;
    else if (s21_token->x == 1 || s21_token->X == 1)
      base = 16;
    fooConvertUDecOctHexToStr(ResultStr, Num, base);

    if (s21_token->flSharp == 1 && ResultStr[0] != '0') {
      if (s21_token->o == 1) {
        s21_strcpy(s21_token->SpaceOrSign, "0");
        s21_token->flSpaceOrSign = 1;
      } else if (s21_token->x == 1 || s21_token->X == 1) {
        s21_strcpy(s21_token->SpaceOrSign, "0x");
        s21_token->flSpaceOrSign = 2;
      }
    }
    /*if (s21_token->flSharp == 1 && Num != 0) {
      if (s21_token->o == 1) {
        char temp[SIZEBUFF] = {'\0'};
        s21_strcpy(temp, ResultStr);
        s21_strcpy(ResultStr, "0");
        s21_strcat(ResultStr, temp);
      }
    }*/
  }
}

int fooConvertUDecOctHexToStr(char *ResultStr, unsigned long Num, int base) {
  char buffer[SIZEBUFF] = {'\0'};
  char HexNum[] = "0123456789abcdef";
  int i = 0;

  do {
    buffer[i] = HexNum[Num % base];
    // buffer[i] = (char)(Num % base + 48);
    i += 1;
    Num = Num / base;
  } while (Num != 0);

  /*  if (fl_minus == 1) s21_strcpy(ResultStr, "-");
  for (int i = 0; Num != 0; Num = Num / base) {
    buffer[i] = (char)(Num % base + 48);
    i += 1;
  }*/

  int lenNum = (int)s21_strlen(buffer);  // + fl_minus;
  for (int j = 0 /*fl_minus*/; j < lenNum; j += 1)
    ResultStr[j] = buffer[lenNum - 1 - j];
  return (int)s21_strlen(ResultStr);
}

void fooPasteSpaceOrZero(char *ResultStr, struct fl_token s21_token) {
  char ch = ' ';
  if (s21_token.flZero == 1) {
    if (s21_token.SpecInt == 1 && s21_token.flPrec == 0 &&
        s21_token.flMinus == 0)
      ch = '0';
    else if (s21_token.SpecFloat == 1 && s21_token.flMinus == 0)
      ch = '0';
  }
  s21_memset(ResultStr, ch, s21_token.widht);
}
void fooDefaultVal(struct fl_token *s21_token) {
  if (s21_token->d == 1 || s21_token->o == 1 || s21_token->u == 1 ||
      s21_token->x == 1 || s21_token->x == 1 || s21_token->X == 1 ||
      s21_token->p == 1)
    s21_token->SpecInt = 1;
  if (s21_token->f == 1 || s21_token->e == 1 ||
      s21_token->E == 1 ||  // e, E, f, g и G
      s21_token->f == 1 || s21_token->g == 1 || s21_token->G == 1) {
    s21_token->SpecFloat = 1;
    if (s21_token->flPrec == 0) {
      s21_token->flPrec = 1;
      s21_token->valPrec = 6;
    } else if (s21_token->flPrec == 1 && s21_token->valPrec == 0 &&
               (s21_token->g == 1 || s21_token->G == 1))
      s21_token->valPrec = 1;
    else if (s21_token->flPrec == 1 && s21_token->valPrec == 0 &&
             s21_token->flSharp == 0)
      s21_token->flPrec = 0;
  }
  if (s21_token->u == 1 || s21_token->o == 1 || s21_token->x == 1 ||
      s21_token->X == 1)
    s21_token->flPlus = 0;
}

void fooSpaceOrSign(long double *Num, struct fl_token *s21_token) {
  if (*Num < 0) {
    *Num = *Num * -1;
    s21_token->flSpaceOrSign = 1;  //взводим флаг, что нужен знак
    s21_strcpy(s21_token->SpaceOrSign, "-");
  } else if (s21_token->flPlus == 1) {
    s21_strcpy(s21_token->SpaceOrSign, "+");
    s21_token->flSpaceOrSign = 1;
  } else if (s21_token->flSpace == 1) {
    s21_strcpy(s21_token->SpaceOrSign, " ");
    s21_token->flSpaceOrSign = 1;
  }
  if (isinf(*Num) || isnan(*Num)) s21_token->flZero = 0;
}

char *s21_strcpy(char *dest, const char *src) {
  s21_size_t i = 0;
  for (; src[i] != '\0'; i++) {
    dest[i] = src[i];
  }
  dest[i] = '\0';

  return dest;
}

char *s21_strcat(char *dest, const char *src) {
  char *answer = dest;  // Сохраняем указатель на начало строки
  s21_size_t i = 0;
  dest = dest + s21_strlen(dest);  // Двигаем указатель на конец строки
  for (; src[i] != '\0'; i++) {
    dest[i] = src[i];
  }
  dest[i] = '\0';
  return answer;
}