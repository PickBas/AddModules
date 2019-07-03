#include "../include/CreationCModule.h"

void CreationCModule(){
    cout << "Enter module's name:" << endl;
    string ModuleName = "";
    getline(cin.ignore(1, '\n'), ModuleName);
    CreationHeaderC(ModuleName);
    CreationCFile(ModuleName);
    cout << "C module \"" << ModuleName << "\" has been created" << endl << endl;
}

void CreationHeaderC(string ModuleName){
    string header = ModuleName + ".h";
    cout << "Header \"" << header << "\" is being created..." << endl;
    ofstream Fheader(header);
    string prag = "#ifndef ";
    string _h = "";
    for(int i = 0; i < ModuleName.size(); ++i){
        if(ModuleName[i] >= 97 && ModuleName[i] <= 122) ModuleName[i] -= 32;
        _h = _h + ModuleName[i];
    }
    _h = _h + "_H";
    prag = prag + _h;
    Fheader << prag << endl;
    prag = "";
    prag = "#define " + _h;
    Fheader << prag << endl << endl << endl << endl;
    prag = "";
    prag = "#endif //" + _h;
    Fheader << prag;
    Fheader.close();
    cout << "Header \"" << header << "\" has been created!" << endl << endl; 
}

void CreationCFile(string ModuleName){
    string CFile = ModuleName + ".c";
    cout << "C file \"" << CFile << "\" is being created..." << endl;
    ofstream FCppFile(CFile);
    string include = "#include \"" + ModuleName + ".h\"";
    FCppFile << include << endl;
    FCppFile.close();
    cout << "C file \"" << CFile << "\" has been created!" << endl << endl; 
}