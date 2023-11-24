#include "Addons.h"

Prisoners::Prisoners()
{
    left = right = nullptr;
    this->relative_1 = this->relative_2 = nullptr;
}

Prisoners::Prisoners(Person data)
{
    left = right = nullptr;
    this->root = data;
}

Prisoners::~Prisoners()
{
    if (this->left != nullptr)
        delete left;
    if (this->right != nullptr)
        delete right;
    left = right = nullptr;
}

Prisoners *Prisoners::search(Prisoners *chunk, string data)
{
    if (data < this->root.ID)
        return this->search(chunk->left, data);
    else if (data > this->root.ID)
        return this->search(chunk->right, data);
    else
        return chunk;
}

Person::Person(string ID, string name)
{
    this->ID = ID;
    this->name = name;
}

/*what thw shit is wrong with the shit is the fish cake
kyaa msla hee tre ko bhens ki dum tera error ni kht m ho k de rha he wtdqjnedjneljnejbw*/
ostream &operator<<(ostream &out, Prisoners *data)
{
    if (data != nullptr)
    {
        out << data->left;
        out << data->root;
        out << data->right;
    }
    return out;
}

void Capture_date::cal_expected_date(Capture_date cap_on, string sentence)
{
    double num = stod(sentence); // ye string s double m number change kar k de ga
    int size = sentence.size();  // ye string ka size hai;
    string yearOrmonth;

    for (int i = 0; i < size; i++)
    {
        if (sentence[i] == 'y' || sentence[i] == 'Y') // agr sentence years m hai to yaha s year ah jai ga
        {
            yearOrmonth = "year";
            break;
        }
        if (sentence[i] == 'm' || sentence[i] == 'M') // agr sentence month m hai to yaha s month ah jai ga
        {
            yearOrmonth = "month";
            break;
        }
    }

    if (yearOrmonth == "year")
    {
        num = num * 12.0;
    }

    int monthCap;
    int yearCap = stoi(cap_on.year); // captured on wala year

    for (int i = 0; i < 12; i++)
    {
        if (Constants::monthNames[i] == cap_on.month)
        {
            monthCap = i + 1;
            break;
        }
    }

    monthCap += static_cast<int>(num);
    if (monthCap > 12)
    {
        yearCap += monthCap / 12; 
        monthCap %= 12;
    }
    this->date = cap_on.date;
    this->month = Constants::monthNames[monthCap - 1];
    this->year = to_string(yearCap);
}
