#include <iostream>
#include <string>
#include <cstring>
#include <fstream>

void CreationHeader(std::string ModuleName){
	std::string header = ModuleName + ".h";
	std::ofstream Fheader(header);
	std::string prag = "#ifndef ";
	std::string _h = "";

    	for(int i = 0; i < ModuleName.size(); ++i){
		if(ModuleName[i] >= 97 && ModuleName[i] <= 122) ModuleName[i] -= 32;
		_h = _h + ModuleName[i];
    	}

    	_h = _h + "_H";
    	prag = prag + _h;
    	Fheader << prag << '\n';
    	prag = "";
    	prag = "#define " + _h;
    	Fheader << prag << "\n\n\n\n";
    	prag = "";
    	prag = "#endif //" + _h;
    	Fheader << prag;
    	Fheader.close(); 
}


void CreationFile(char lang, std::string ModuleName){
	std::string File = "";
	if (lang == 'c' || lang == 'C')
		File = ModuleName + ".c";
	else 
		File = ModuleName + ".cpp";
	std::ofstream SrcFile(File);
	std::string include = "#include \"" + ModuleName + ".h\"";
    	SrcFile << include << '\n';
    	SrcFile.close(); 
}


void CreationModule(char lang, char *ModuleName){
        std::string ModuleNameStr(ModuleName);
        CreationHeader(ModuleNameStr);
        CreationFile(lang, ModuleNameStr);

}

void help(){
	std::cout << "usage: AddModle [languge] [module name]\n\n";
	std::cout << "language:\n";
	std::cout << "	C	to create C module;\n";
	std::cout << "	+	to create C++ module.\n";
}

int main(int argc, char **argv){
	if (argc == 3 && argv[1][0] != 'c' && argv[1][0] != 'C' && argv[1][0] != '+'){
		std::cout << "Invalid input!\n";
		return 1;
	}
	switch (argc){
		case 2:
			help();
			break;
		case 3:
			CreationModule(argv[1][0], argv[2]);
			break;
		default:
			std::cout << "Invalid input!\n";
	}
    	return 0;
}

// Program's author is Kirill Sayed. Good luck!
