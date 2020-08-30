#include <iostream>

using namespace std;

//O(mlogn)
int ejLog(int a[5][6], int row, int col, int fin = 0, int start = 0, int retCol = 0) //Toca definir que fin, start y retCol son igual a 0 en la función ya que no funciona si se define despues.
{
    int nextCol;

    if(start > fin)
    {
        return 0;
    }  
    if(fin == 0)
    {
        fin = 5;
    }
        
    bool build = false;
    int middle = (start + fin)/2;

    for(int i = 0; i < col; i++)
    {
        if(a[middle][i] == 0)
        {
            build = true;

            if(middle == 0)
            {
                return i;
            }
            
            nextCol = ejLog(a, row, col, middle, start, retCol);

            if(nextCol < 0)
            {
                retCol = i;
            }   
            else
            {
                retCol = nextCol;
                break;
            }

        }
    }

    if(build == false && ((middle + fin)/2) == middle)
    {
        return 0;
    }
    if(build)
    {
        return retCol;
    }

    return ejLog(a, row, col, fin, middle, retCol);
}

//O(m+n)
template <size_t Row, size_t Col> //Size_t sirve para representar el tamaño de cualquier objeto
int MplusN(int(&city)[Row][Col])
{
    for(int i = 0; i < Row; i++)
    {
        for(int j = 0; j < Col; j++)
        {
            if(city[i][j]==0)
            {
                return j;
            }

        }
        return 0;
    }


}

//La implementación del punto a tardará más tiempo que el del punto b debido a que este presenta una menor eficiencia al ser de tipo logaritmica.

int main()
{
    int ansA, ansB;
    int city[5][6] = {{1, 1, 1, 0, 1}, {0, 1, 0, 0, 0}, {0, 1, 0, 0, 0}, {0, 1, 0, 0, 0}, {0, 0, 0, 0, 0}};

    ansA = ejLog(city, 5, 6);
    ansB = MplusN(city);

    cout << "The answer for 3.a is: " << ansA << endl;
    cout << "The answer for 3.b is: " << ansB << endl;
}
