#include <iostream>
#include "cstring"

int main(){
    int n;
    int totalpoint=0;
    int totalsegment=0;
    int totaltriangle=0;
    int totalrefusé=0;
    std::cin>>n;
    for( int i=1; i<=n; i++){
        int s;
        std::string type;
        std::cin>> type >>s;
        if(s<0){
            s=0;
        }
        if(type=="POINT"){
           totalpoint+=s;
           int restant=0;
           std::cout<< type <<" "<<s<< " "<<s<<" POINT "<<restant;
        
        }
        else if(type=="LINES"){
            int segment=s/2;
            int restant= s%2;
            std::cout<< type<<" "<<s<<" "<<segment<<" SEGMENT "<<restant;
            totalsegment+=segment;
        }
        else if(type=="LINE_STRIP"){
            if(s>=2){
                int segment=s-1;
                int restant=0;
                std::cout<< type<<" "<<s <<" "<<segment<<" SEGMENT "<< restant;
                totalsegment+=segment;
            }
            else{
                int segment=0;
                int restant=s;
                std::cout<< type<<" "<<s <<" "<<segment<<" SEGMENT ";
            }
            
        }
        else if(type=="TRIANGLES"){
            int triangle=s/3;
            int restant=s%3;
            std::cout<<type<<" "<<s<<" "<<triangle<<" TRIANGLE ";
            totaltriangle+=triangle;
        }
        else if(type=="TRIANGLE_STRIP"||"TRIANGLE_FAN" ){
            if(s>=3){
                int triangle=s-2;
                int restant=0;
                std::cout<<type<<" "<<s<<" "<<triangle<<" TRIANGLE ";
                totaltriangle+=triangle;
            }
            else{
                int triangle=0;
                int restant=0;
                std::cout<<type<<" "<<s<<" "<<triangle<<" TRIANGLE "<<restant;
                totaltriangle+=triangle;
            }
        }
        else{
            std::cout<< type<<" "<<s<<" refusé";
            totalrefusé++;
        }
    }
    std::cout<< "POINT"<< totalpoint<<std::endl;
    std::cout<< "SEGMENT"<< totalsegment<<std::endl;
    std::cout << "TRIANGLES"<< totaltriangle<<std::endl;
    std::cout <<"REFUSE"<< totalrefusé<<std::endl;
}