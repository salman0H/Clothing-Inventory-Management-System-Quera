#include <iostream>
using namespace std;


class date {
    friend istream &operator>>(istream &in, date &obj);
    friend ostream &operator<<(ostream &out, date &obj);
public:
    date(const date &obj) {
        day = obj.day;
        month = obj.month;
        year = obj.year;
    }
    date(int, int, int);
    date() {
        day = 0;
        month = 0;
        year = 0;
    }
    void setdate(int, int, int);
    int getday() {
        return day;
    }
    int getmonth() {
        return month;
    }
    int getyear() {
        return year;
    }
    void displayinfo() {
             cout<< day << '/' << month << '/' << year << " ";
    }
private:
    int day;
    int month;
    int year;
    int days_of_month[13] = {0, 30, 30, 30, 30, 30, 30, 31, 31, 31, 31, 31, 31};
};

date::date(int _d, int _m, int _y) {
    setdate(_d, _m, _y);
}
void date::setdate(int _day, int _month, int _year) {
    if (_year > 0) {
        year = _year;
    } else {
        year = 1402;
    }

    if (_month > 0 && _month < 13) {
        month = _month;
    } else {
        month = 1;
    }

    if (_day > 0 && _day <= days_of_month[month]) {
        day = _day;
    } else {
        day = 1;
    }
}
istream &operator>>(istream &in, date &obj) {
    in >> obj.day;
    in >> obj.month;
    in >> obj.year;
    return in;
}

ostream &operator<<(ostream &out, date &obj) {
    out << obj.day << '/' << obj.month << '/' << obj.year <<" ";
    return out;
}
///------------------------------------------------------------------------------------
class Clothing
{
    friend ostream &operator <<(ostream &out,Clothing &obj);
    friend istream &operator >>(istream &in,Clothing &obj);
public:
    /*Clothing()
    {
    }*/
    Clothing(double _price, int _size, string _color,date p = date(1,1,1402))
    {
        production = date();
        setprice(_price);
        setsize(_size);
        setcolor(_color);
    }
    Clothing()
    {
        price = 0;
        size = 0;
        color = "";
        production = date(0,0,0);
    }
    void setproduction(int d,int m,int y)
    {
        production.setdate(d,m,y);
    }
    void setprice(double p)
    {
        price = p;
    }
    void setsize(int s)
    {
        if(s > 0 && s < 10)
        {
            size = s;
        }else{
            size = 0;
        }
    }
    void setcolor(string c)
    {
        color = c;
    }
    double getprice()
    {
        return price;
    }
    int getsize()
    {
        return size;
    }
    string getcolor()
    {
        return color;
    }
    date getproduction()
    {
        return production;
    }
    Clothing operator =(Clothing &obj)
    {
        obj.size = size;
        obj.price = price;
        obj.color = color;
        return obj;
    }
    bool operator ==(Clothing &obj)
    {
        if(price == obj.price && size == obj.size && color == obj.color)
            return true;
        return false;
    }
    void show()
    {
        production.displayinfo();
    }
    int getday()
    {
        int day = production.getday();
        return day;
    }
    int getmounth()
    {
        int mounth = production.getmonth();
        return mounth;
    }
private:
    double price;
    int size;
    string color;
    date production;
};
ostream &operator <<(ostream &out,Clothing &obj){
    out << obj.price <<" "<<obj.size<<" "<<obj.color<<" "<<obj.production<<endl;
    return out;
}
istream &operator >>(istream &in,Clothing &obj){
    in >> obj.price;
    in >> obj.size;
    in >> obj.color;
    in >> obj.production;
    return in;
}
///------------------------------------------------------------------------------------
class Shirt : public Clothing
{
    friend ostream &operator <<(ostream &out,Shirt &obj);
    friend istream &operator >>(istream &in,Shirt &obj);
public:
    /*Shirt()
    {
    }*/
    Shirt()
    {
        tedad_dokmeha = 0;
        toole_astin = 0;
    }
    Shirt(double _price,int _size, string _color,date _p,int _tedad_dokmeha,float _toole_astin) : Clothing(_price,_size,_color,_p)
    {
        settd(_tedad_dokmeha);
        setta(_toole_astin);
    }
    void settd(int td)
    {
        tedad_dokmeha = td;
    }
    void setta(float ta)
    {
        toole_astin = ta;
    }
    int gettd()
    {
        return tedad_dokmeha;
    }
    float getta()
    {
        return toole_astin;
    }
    Shirt operator =(Shirt &obj)
    {
        obj.tedad_dokmeha = tedad_dokmeha;
        obj.toole_astin = toole_astin;
        return obj;
    }
    bool operator ==(Shirt &obj)
    {
        if(tedad_dokmeha == obj.tedad_dokmeha && toole_astin == obj.toole_astin)
            return true;
        return false;
    }
private:
    int tedad_dokmeha;
    float toole_astin;
};
ostream &operator <<(ostream &out,Shirt &obj){
    out <<obj.getprice() <<" "<<obj.getsize()<<" "<<obj.getcolor()<<" ";
    obj.show();
    out <<obj.tedad_dokmeha<<" "<<obj.toole_astin<<endl;
    return out;
}
istream &operator >>(istream &in,Shirt &obj){
    double price;
    int size;
    string color;
    date time;
    in >> price;
    in >> size;
    in >> color;
    in >> time;
    obj.setprice(price);
    obj.setsize(size);
    obj.setcolor(color);
    in >> obj.tedad_dokmeha;
    in >> obj.toole_astin;
    return in;
}
///------------------------------------------------------------------------------------
class Pants : public Clothing
{
    friend ostream &operator <<(ostream &out,Pants &obj);
    friend istream &operator >>(istream &in,Pants &obj);
public:
    /*Pants()
    {
    }*/
    Pants()
    {
        leg_length  = 0;
        doore_kamar = 0;
    }
    Pants(double _price,int _size, string _color,date _p,float _leg_length,float _doore_kamar) : Clothing(_price,_size,_color,_p)
    {
        setll(_leg_length);
        setdk(_doore_kamar);
    }
    void setll(float ll)
    {
        leg_length = ll;
    }
    void setdk(float dk)
    {
        doore_kamar = dk;
    }
    float getll()
    {
        return leg_length;
    }
    float getdk()
    {
        return doore_kamar;
    }
    Pants operator =(Pants &obj)
    {
        obj.leg_length = leg_length;
        obj.doore_kamar = doore_kamar;
        return obj;
    }
    bool operator ==(Pants &obj)
    {
        if(leg_length == obj.leg_length && doore_kamar == obj.doore_kamar)
            return true;
        return false;
    }
private:
    float leg_length;
    float doore_kamar;
};
ostream &operator <<(ostream &out,Pants &obj){
    out <<obj.getprice()<<" "<<obj.getsize()<<" "<<obj.getcolor()<<" ";
    obj.show();
    out <<obj.leg_length<<" "<<obj.doore_kamar<<endl;
    return out;
}
istream &operator >>(istream &in,Pants &obj){
    double price;
    int size;
    string color;
    date time;
    in >> price;
    in >> size;
    in >> color;
    in >> time;
    obj.setprice(price);
    obj.setsize(size);
    obj.setcolor(color);
    in >> obj.leg_length;
    in >> obj.doore_kamar;
    return in;
}
///------------------------------------------------------------------------------------
int main() {
    int n,m;
    cout << "Enter a number for your Shirt:"<<endl;
    cin >> n;
    cout << "Enter a number for your Pants:"<<endl;
    cin >> m;
    Shirt Cloth[n];
    Pants Cloth2[m];
    for(int i=0;i<n;i++)
    {
        cin >> Cloth[i];
    }
    for(int i=0;i<m;i++)
    {
        cin >> Cloth2[i];
    }

    for(int i=0;i<n;i++)
    {
        if(Cloth[i].getday() % 2 != 0)
        {
            cout << Cloth[i];
        }
        if(Cloth2[i].getday() % 2 != 0)
        {
            cout << Cloth2[i];
        }
    }
    for(int i=0;i<m;i++)
    {
        if(Cloth[i].getmounth() % 2 == 0)
        {
            cout << Cloth[i];
        }
        if(Cloth2[i].getmounth() % 2 == 0)
        {
            cout << Cloth2[i];
        }
    }
    return 0;
}
