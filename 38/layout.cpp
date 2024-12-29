class S_A
{
public:
    char m_a[4]{'A','A','A','A'};
    char m_b[3]{'B','B','B'};
    char m_c[4]{'C','C','C','C'}; 
};

class T_A
{
private:
    char m_a[4]{'A','A','A','A'};
public:
    char m_b[3]{'B','B','B'};
    char m_c[4]{'C','C','C','C'}; 
};


int main(void)
{
    //S_A obj1;
    T_A obj2;
}