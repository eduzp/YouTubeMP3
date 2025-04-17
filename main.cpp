#include <iostream>
#include <string>
#include <cstdlib>

int main() {
    std::string url;

    // Altera o t�tulo da janela do terminal
    std::system("title MP3 Download");

    // Aqui ir� sua URL desejada para download (YouTube).
    std::cout << "Insira a URL: ";
    std::getline(std::cin, url);

    // IF ELSE padr�o
    if (url.empty()) {
        std::cout << "URL inv�lida.\n";
        return 1;
    }

    // Caminhos relativos para os execut�veis yt-dlp e ffmpeg (na pasta libs)
    std::string yt_dlp_path = ".\\libs\\yt-dlp.exe";  // Caminho para o yt-dlp
    std::string ffmpeg_path = ".\\libs\\ffmpeg.exe";  // Caminho para o ffmpeg (caso precise)

    // Comando para extrair o �udio da URL e salvar na pasta mp3
    std::string comando = yt_dlp_path + " -f bestaudio --extract-audio --audio-format mp3 --audio-quality 0 --ffmpeg-location "
                          + ffmpeg_path + " --paths .\\mp3 \"" + url + "\"";

    std::cout << "Processando e baixando o �udio...\n";

    // Execu��o do comando
    int resultado = std::system(comando.c_str());

    //Somente caso d� erro possa ler.
    std::system("pause");

    // PADR�O
    if (resultado == 0) {
        std::cout << "CONCLUIDO! Verifique o diret�rio.\n";
    } else {
        std::cout << "ERRO! N�o foi poss�vel baixar o arquivo, tente novamente.\n";
    }

    return 0;
}

//@eduzp//
//lembrando � necess�rio o uso do yt-dlp e ffmpeg, inclusos no projeto. N�o mude o diret�rio dos arquivos.
//Se for atr�s voc� consegue fazer em Python, ele possu� biblioteca do ffmpeg e yt-dlp integradas que fazem o processo autom�tico.
//Futuramente talvez mude pra C# e adicione GUI neste c�digo.
//Talvez adicione multifun��es como mp4 e o download de outras plataformas(sociais).
