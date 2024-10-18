#include <iostream>
#include <fstream>
#include <string>
#include <vector>

class FileHandler {
public:
    FileHandler(const std::string& inputFileName, const std::string& outputFileName) 
        : inputFile(inputFileName), outputFile(outputFileName) {}

    void openFiles() {
        inputStream.open(inputFile);
        if (!inputStream.is_open()) {
            throw std::runtime_error("Errore nell'aprire il file di input");
        }
        outputStream.open(outputFile);
        if (!outputStream.is_open()) {
            throw std::runtime_error("Errore nell'aprire il file di output");
        }
    }

    void closeFiles() {
        if (inputStream.is_open()) inputStream.close();
        if (outputStream.is_open()) outputStream.close();
    }

    std::ifstream& getInputStream() { return inputStream; }
    std::ofstream& getOutputStream() { return outputStream; }

private:
    std::string inputFile;
    std::string outputFile;
    std::ifstream inputStream;
    std::ofstream outputStream;
};

char spostaCarattere(char c, int chiave) {
    if (c >= 'A' && c <= 'Z') {
        return ((c - 'A' + chiave + 26) % 26) + 'A'; // Gestisce anche chiavi negative
    } else if (c >= 'a' && c <= 'z') {
        return ((c - 'a' + chiave + 26) % 26) + 'a'; // Gestisce anche chiavi negative
    }
    return c; // Non modificare caratteri non alfabetici
}

void crittografa(FileHandler& fh, int chiave) {
    std::string buffer;
    while (std::getline(fh.getInputStream(), buffer)) {
        for (char& c : buffer) {
            c = spostaCarattere(c, chiave);
        }
        fh.getOutputStream() << buffer << std::endl; // Scrive la riga crittografata
    }
}

void decrittografa(FileHandler& fh, int chiave) {
    crittografa(fh, -chiave); // Usa la crittografia con chiave negativa
}

int main(int argc, char* argv[]) {
    if (argc != 5) {
        std::cerr << "Uso: " << argv[0] << " <azione> <file_input> <file_output> <chiave>" << std::endl;
        std::cerr << "Azione: -e per crittografare, -d per decrittografare" << std::endl;
        return EXIT_FAILURE;
    }

    int chiave = std::stoi(argv[4]);
    if (chiave < 0) {
        std::cerr << "Errore: La chiave deve essere un numero positivo." << std::endl;
        return EXIT_FAILURE;
    }

    try {
        FileHandler fileHandler(argv[2], argv[3]);
        fileHandler.openFiles();

        if (std::string(argv[1]) == "-e") {
            crittografa(fileHandler, chiave);
        } else if (std::string(argv[1]) == "-d") {
            decrittografa(fileHandler, chiave);
        } else {
            std::cerr << "Errore: Azione non valida. Usa -e o -d." << std::endl;
            fileHandler.closeFiles();
            return EXIT_FAILURE;
        }

        fileHandler.closeFiles();
    } catch (const std::exception& e) {
        std::cerr << e.what() << std::endl;
        return EXIT_FAILURE;
    }

    return EXIT_SUCCESS;
}
