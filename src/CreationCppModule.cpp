#include "../include/CreationCppModule.h"

void CreationCppModule(){
    cout << "Enter module's name:" << endl;
    string ModuleName = "";
    getline(cin.ignore(1, '\n'), ModuleName);
    CreationHeaderCpp(ModuleName);
    CreationCppFile(ModuleName);
    cout << "C++ module \"" << ModuleName << "\" has been created!" << endl << endl;
}

void CreationHeaderCpp(string ModuleName){
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

void CreationCppFile(string ModuleName){
    string CppFile = ModuleName + ".cpp";
    cout << "C++ file \"" << CppFile << "\" is being created..." << endl;
    ofstream FCppFile(CppFile);
    string include = "#include \"" + ModuleName + ".h\"";
    FCppFile << include << endl;
    FCppFile.close();
    cout << "C++ file \"" << CppFile << "\" has been created!" << endl << endl; 
}