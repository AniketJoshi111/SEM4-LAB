#include<iostream>
#include<fstream>
#include<ostream>
using namespace std;

class FileHandling
{
    private:
    fstream f;
    char buffer[40];
    public:
       void write()
       {
           f.open("demo.txt",ios::out);
           if(!f)
           {
              cout<<"Error opening the file "<<endl;
           }
           else{
              f << "Aniket"<<endl;
              f << "Advait"<<endl;
              f << "suvrat"<<endl;

           }
           f.close();
       }
       void read()
       {

           if(!f){
            cout<<"error opening the file 0"<<endl;
           }
           else 
           {
              int record = 1;
              while(f.getline(buffer,40))
              {
                 cout<<"Record -"<<record++<<":"<<buffer<<endl;
              }
              f.close();
           }
       }
       void removeFile()
       {
          if(remove("demo.txt")!=0)
          {
            cout<<"Error removing the file"<<endl;
          }
          else{
            cout<<"File removed successfully"<<endl;
          }
       }

};
int main()
{
    FileHandling f;
    f.write();
    f.read();
    f.removeFile();
    return 0;
}