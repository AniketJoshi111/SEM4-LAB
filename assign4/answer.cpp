#include<bits/stdc++.h>
using namespace std;

class Hashing{
    private:
        int arr[10];
    public:
        void initArr(){
            for(int i=0;i<10;i++){
                arr[i]=-1;
            }
        }
        int hashValue(int phNumber){
            return (phNumber%10);
        }
        void insertWithoutReplacement(int phNumber){
            int hash=hashValue(phNumber);
            if(arr[hash]==-1){
                arr[hash]=phNumber;
            }
            else{
                while(arr[hash]!=-1){
                    hash=(hash+1)%10;
                }
                arr[hash]=phNumber;
            }
        }
        void insertWithReplacement(int phNumber){
            int hash=hashValue(phNumber);
            if(arr[hash]==-1){
                arr[hash]=phNumber;
            }
            else{
                if(hash==hashValue(arr[hash])){
                    while(arr[hash]!=-1){
                        hash=(hash+1)%10;
                    }
                    arr[hash]=phNumber;
                }
                else{
                    int replace=arr[hash];
                    arr[hash]=phNumber;
                    while(arr[hash]!=-1){
                        hash=(hash+1)%10;
                    }
                    arr[hash]=replace;
                }
            }
        }
        void Delete(int phNumber){
            int hash=hashValue(phNumber);
            arr[hash]=-1;
            int dupHash=(hash+1)%10;
            while(dupHash!=hash){
                if(hashValue(arr[dupHash]) == hash){
                    arr[hash]=arr[dupHash];
                    arr[dupHash]=-1;
                    break;
                }
                dupHash=(dupHash+1)%10;
            }

        }
        void display(){
            for(int i=0;i<10;i++){
                if(arr[i]!=-1){
                    cout<<i<<":"<<arr[i]<<endl;
                }else{
                    cout<<i<<":"<<endl;
                }
                
            }
        }
};
int main(){
    Hashing obj;
    obj.initArr();
    obj.insertWithReplacement(3);
    obj.insertWithReplacement(33);
    obj.insertWithReplacement(4);
    obj.insertWithReplacement(6);    
    obj.insertWithReplacement(43);
    obj.display();
    cout<<endl;
    obj.Delete(3);
    obj.display();
    return 0;
}