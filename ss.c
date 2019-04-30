
int main()
{
    long long i, p = 1;
    char r[33] = "";
    char scode[33] = "";
    char binary3[33] = "", b2u = 0, b2s = 0, b2o = 0, b2t = 0, oct = 0;
    
    char bcode[100] = "";
    printf("Enter a Binary Number: ");
    scanf("%s", r);
    int len = strlen(r);
    for (i = 0; i < len; i++)
    {
        scode[i] = r[i];
    }

    for (i = len - 1; i >= 0; i--)
    {
        b2u += (r[i]-48) * p;
        p *= 2;
    }

    printf("b2u(%s) = %lld", scode, b2u);
    printf("\n");


    p = 1;
    if (r[0] == 49)
    {
         for (i = len - 1; i >= 1; i--)
         {
             b2s += (r[i]-48) * p;
             p *= 2;
         }
    }
    else
    {
         for (i = len - 1; i >= 0; i--)
         {
             b2s += (r[i]-48) * p;
             p *= 2;
         }
    }
    if (r[0] == 49)
    {
       printf("b2s(%s) = -%lld", scode, b2s);
       printf("\n");
    }
    else
    {
        printf("b2s(%s) = %lld", scode, b2s);
        printf("\n");

    }

    for (i = len - 1; i >= 0; i--)
    {
        if (r[i] == 49)
        {
            r[i] = 48;
        }
        else
        if (r[i] == 48)
        {
            r[i] = 49;

        }

        b2o += (r[i]-48) * p;
        p *= 2;
    }
    if (r[0] == 48)
    {
       printf("b2o(%s) = -%lld", scode, b2o);
       printf("\n");
    }
    else
    {
        printf("b2o(%s) = %lld", scode, b2o);
        printf("\n");

    }
    b2t = b2o + 1;
    if (r[0] == 48)
    {
       printf("b2t(%s) = -%lld", scode, b2t);
       printf("\n");
    }
    else
    {
        printf("b2t(%s) = %lld", scode, b2t);
        printf("\n");

    }

    long long NewDecimal = b2u;
    /// For Converting Binary To octal Form
    p = 1;
    while (b2u != 0)
    {
        oct += (b2u % 8) * p;
                b2u /= 8;
                p *= 10;
    }
    printf("oct(%s) = %lld", scode, oct);
    printf("\n");

    /// For Converting Binary to bcode form
   
    long long temp = 0, i = 0;
    while (NewDecimal != 0)
    {
        temp = NewDecimal % 16;
        if (temp < 10)
        {
            temp = temp + 48;
        }
        else
        {
            temp = temp + 55;
        }
        bcode[i] = temp;
        NewDecimal = NewDecimal/16;
        i++;
    }
    printf("bcode(%s) = 0x", scode);
    for (i = i -1; i >= 0; i--)
    {
        printf("%c", bcode[i]);
    }

    

    int p2=1;
    int a=0;
    int len2 = strlen(scode);
    int f = (int)((len2-1) / 4);
    
    for (int i=len2-1; i>=0; i--) 
    {
       a=a+((int)scode[i] -48)*p2;
       p2=p2*2;

       if (p2==16) 
       {
          if (a>9)
               bcode[f--] = (char)(a+55);  
          else      
               bcode[f--] = (char)(a+48);
          a=0;
          p2=1;
       }

    }

    if (a>9)
     bcode[f--] = (char)(a+55);  
    else    

    bcode[f--] = (char)(a+48);

    for (int i=0; i<=(len2-1)/4; i++) 
    {
        printf("%c", bcode[i]);  
    }
  printf("\n");

  return 0;
}
