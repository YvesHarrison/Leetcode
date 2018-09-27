class Solution {
public:
    int maximumSwap(int num) {
        string number=to_string(num);
        int loc1=-1,loc2=-1,loc3=-1;
        int max=-1;
        for(int i=number.size()-1;i>=0;--i){
            if(number[i]-'0'>max){
                max=number[i]-'0';
                loc1=i;
            }
            if(number[i]-'0'<max){
                loc2=i;
                loc3=loc1;//to ensure the bigger digit locates behind the smaller I wanna swap 
            }
        }
        if(loc2==-1) return num;
        swap(number[loc3],number[loc2]);
        return stoi(number);
    }
};
