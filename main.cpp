#include <iostream>
#include <fstream>
#include <vector>
#include <cmath>
#include "table.h"
using namespace std;
void True_to_Cesar()
{
     string Cesar;
        cin >> Cesar;
        int dec_num=0,c=1;
        char cur_symb='0';
        for(int i=0; i<Cesar.size(); ++i)
        {
            if(Cesar[i]=='I' and Cesar[i+1]=='V')
            {
                switch(cur_symb)
                {
                case 'I':
                    dec_num+=1*c;
                    break;
                case 'V':
                    dec_num+=5;
                    break;
                case 'X':
                    dec_num+=10*c;
                    break;
                case 'L':
                    dec_num+=50;
                    break;
                case 'C':
                    dec_num+=100*c;
                    break;
                case 'D':
                    dec_num+=500;
                    break;
                case 'M':
                    dec_num+=1000*c;
                    break;
                default:
                    break;

                }
                                cur_symb='0';
                dec_num+=4;
                c=1;
                i++;
            }
            else if(Cesar[i]=='X' and Cesar[i+1]=='L')
            {
                switch(cur_symb)
                {
                case 'I':
                    dec_num+=1*c;
                    break;
                case 'V':
                    dec_num+=5;
                    break;
                case 'X':
                    dec_num+=10*c;
                    break;
                case 'L':
                    dec_num+=50;
                    break;
                case 'C':
                    dec_num+=100*c;
                    break;
                case 'D':
                    dec_num+=500;
                    break;
                case 'M':
                    dec_num+=1000*c;
                    break;
                default:
                    break;

                }
                cur_symb='0';
                dec_num+=40;
                c=1;
                i++;
            }
            else if(Cesar[i]=='C' and Cesar[i+1]=='D')
            {
                switch(cur_symb)
                {
                case 'I':
                    dec_num+=1*c;
                    break;
                case 'V':
                    dec_num+=5;
                    break;
                case 'X':
                    dec_num+=10*c;
                    break;
                case 'L':
                    dec_num+=50;
                    break;
                case 'C':
                    dec_num+=100*c;
                    break;
                case 'D':
                    dec_num+=500;
                    break;
                case 'M':
                    dec_num+=1000*c;
                    break;
                default:
                    break;

                }
                cur_symb='0';
                dec_num+=400;
                c=1;
                i++;
            }
            if(Cesar[i]=='I' and Cesar[i+1]=='X')
            {
                switch(cur_symb)
                {
                case 'I':
                    dec_num+=1*c;
                    break;
                case 'V':
                    dec_num+=5;
                    break;
                case 'X':
                    dec_num+=10*c;
                    break;
                case 'L':
                    dec_num+=50;
                    break;
                case 'C':
                    dec_num+=100*c;
                    break;
                case 'D':
                    dec_num+=500;
                    break;
                case 'M':
                    dec_num+=1000*c;
                    break;
                default:
                    break;

                }
                cur_symb='0';
                dec_num+=9;
                c=1;
                i++;
            }
            else if(Cesar[i]=='X' and Cesar[i+1]=='C')
            {
                switch(cur_symb)
                {
                case 'I':
                    dec_num+=1*c;
                    break;
                case 'V':
                    dec_num+=5;
                    break;
                case 'X':
                    dec_num+=10*c;
                    break;
                case 'L':
                    dec_num+=50;
                    break;
                case 'C':
                    dec_num+=100*c;
                    break;
                case 'D':
                    dec_num+=500;
                    break;
                case 'M':
                    dec_num+=1000*c;
                    break;
                default:
                    break;

                }
                cur_symb='0';
                dec_num+=90;
                c=1;
                i++;
            }
            else if(Cesar[i]=='C' and Cesar[i+1]=='M')
            {
                switch(cur_symb)
                {
                case 'I':
                    dec_num+=1*c;
                    break;
                case 'V':
                    dec_num+=5;
                    break;
                case 'X':
                    dec_num+=10*c;
                    break;
                case 'L':
                    dec_num+=50;
                    break;
                case 'C':
                    dec_num+=100*c;
                    break;
                case 'D':
                    dec_num+=500;
                    break;
                case 'M':
                    dec_num+=1000*c;
                    break;
                default:
                    break;

                }
                cur_symb='0';
                dec_num+=900;
                c=1;
                i++;
            }
            else
            {
                if(cur_symb!=Cesar[i])
                {
                    switch(cur_symb)
                    {
                    case 'I':
                        dec_num+=1*c;
                        break;
                    case 'V':
                        dec_num+=5;
                        break;
                    case 'X':
                        dec_num+=10*c;
                        break;
                    case 'L':
                        dec_num+=50;
                        break;
                    case 'C':
                    {
                        cout << c*100;
                        dec_num+=100*c;
                        break;
                    }
                    case 'D':
                        dec_num+=500;
                        break;
                    case 'M':
                    {
                        cout << c*1000 << " ";
                        dec_num+=1000*c;
                        break;
                    }
                    default:
                        break;

                    }
                    cur_symb=Cesar[i];
                    c=1;
                }
                else
                     c++;
                if(i+1>=Cesar.size())
                {
                    switch(cur_symb)
                    {
                    case 'I':
                        dec_num+=1*c;
                        break;
                    case 'V':
                        dec_num+=5;
                        break;
                    case 'X':
                        dec_num+=10*c;
                        break;
                    case 'L':
                        dec_num+=50;
                        break;
                    case 'C':
                    {
                        cout << c*100;
                        dec_num+=100*c;
                        break;
                    }
                    case 'D':
                        dec_num+=500;
                        break;
                    case 'M':
                    {
                        cout << c*1000 << 1000 << " ";
                        dec_num+=1000*c;
                        break;
                    }
                    default:
                        break;

                    }
                }
            }

        }
        cout << dec_num;

}
void pas()
{


}
int main()
{

       short switcher;;
       setloacle(0," ");
       cout << "Введите 1 для треугольника Паскаля\nВведите 2 для римских цифр\n";
       for(;;cout << ">")
       {
            cin >> swithcer;
            switch(switcher)
            {
                case 1:
                    pas();
                    break;
                case 2:
                    True_to_Cesar();
                    break;
            }
       }
    return 0;
}
