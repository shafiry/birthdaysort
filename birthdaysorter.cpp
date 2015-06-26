// Radix sort for birthdays 

#include <vector>
#include <iostream>
#include <cstdlib>

using namespace std;

class Birthday{
       public:
       int day;
       int month;
       int year;
       Birthday(int m, int d, int y) : day(d), month(m), year(y) {}
};

class person{
    public:
    Birthday dob;
    person(int m, int d, int y): dob(m, d, y){}
    void formattedprint(){
        cout << dob.month+1 << "/" << dob.day+1 << "/" << dob.year << endl;
    }
};

//implemented with radix sort
vector<person*> sortedbyDob(vector<person*> people){
      vector<vector<person*> > days(31);
      //first sort by day
      for(int i = 0; i < people.size(); i++){
          int d = people[i]->dob.day;
          if(d > 30 || d < 0)
              cout << d << endl;
          days[d].push_back(people[i]);
      }
      //sort by month
      vector<vector<person*> > months(12);
      for(int i = 0; i < days.size(); i++){
          for(int j = 0; j < days[i].size(); j++){
              int m = days[i][j]->dob.month;
              if(m > 11 || m < 0) cout << m << endl;
              months[m].push_back(days[i][j]);
          }      
      }
      //sort by year
      vector<vector<person*> > years(100);
      for(int i = 0; i < months.size(); i++){
          for(int j = 0; j < months[i].size(); j++){
              int y = months[i][j]->dob.year-1914;
              if(y > 99 || y < 0) cout << y << endl;
              years[y].push_back(months[i][j]);
          }      
      }
      cout << "MADE IT" << endl;
      vector<person*> ret;
      for(int i = 0; i < years.size(); i++){
          for(int j = 0; j < years[i].size(); j++){
              ret.push_back(years[i][j]);
          }
      }
      return ret;
}
    
int main(){
    vector<person*> peeps;
    int n = 100;
    for(int i = 0; i < n; i++){
        int month = rand() % 12;
        int day = rand() % 31;
        int year = (rand() % 100) + 1914;
        person* p = new person(month, day, year);
        peeps.push_back(p);
    }
    
    vector<person*> vec = sortedbyDob(peeps);
    for(int i = 0; i < n; i++){
        vec[i]->formattedprint();
    }
}
