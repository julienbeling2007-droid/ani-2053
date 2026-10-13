#include "iostream"
#include "string"

int main(){
    int n;

    std::cin>>n;

    int lus=0;
    int refusé=0;
    int mensonge=0;

    for(int i=0; i<=n; i++){
        std::string nom, octets;
        int taille;
        std::cin>> nom;
        std::cin>> octets;
        std::cin>>taille;
        int position=nom.find_last_of('.');// recupère la position du dernier . du caractère
        std::string extension="";
        if(position!=std::string::npos){
            extension=nom.substr(position+1);
        }
        if(taille<4){
            std::cout<<nom<<"refusé"<<std::endl;    
            refusé++;
        }
        else{
            lus++;

            std::string format="inconnu";
            if(octets.find("89504E47")==0){
                format="PNG";
            }
            else if(octets.find("FFD8FF")==0){
                format="JPEG";
            }
            else if(octets.find("<svg")==0){
                format="SVG";
            }
            if(format=="inconnu"){
                std::cout << nom << "refusé"<<std::endl;
                refusé++;
            }
            else if((format=="PNG" && extension=="png")||(format=="JPEG" && extension=="jpg")||(format=="SVG" && extension=="svg")){

                std::cout<<nom <<" " << format << "ok "<<std::endl;
            }
            else{
                std::cout<< nom << " " << format << "MENT"<<std::endl;
                mensonge ++;
            }

           


        }
    }
    // affichage des statistiques
    std::cout<< "LUS" <<lus<<std::endl;
    std::cout<< "MENSONGE" <<mensonge<<std::endl;
    std::cout<< "REFUSES" <<refusé<<std::endl;

    return 0;
}