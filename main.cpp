#include <iostream>
#include <string>
#include <cstdlib>

int main() {
    std::string url;

    // Altera o título da janela do terminal
    std::system("title MP3 Download");

    // Aqui irá sua URL desejada para download (YouTube).
    std::cout << "Insira a URL: ";
    std::getline(std::cin, url);

    // IF ELSE padrão
    if (url.empty()) {
        std::cout << "URL inválida.\n";
        return 1;
    }

    // Caminhos relativos para os executáveis yt-dlp e ffmpeg (na pasta libs)
    std::string yt_dlp_path = ".\\libs\\yt-dlp.exe";  // Caminho para o yt-dlp
    std::string ffmpeg_path = ".\\libs\\ffmpeg.exe";  // Caminho para o ffmpeg (caso precise)

    // Comando para extrair o áudio da URL e salvar na pasta mp3
    std::string comando = yt_dlp_path + " -f bestaudio --extract-audio --audio-format mp3 --audio-quality 0 --ffmpeg-location "
                          + ffmpeg_path + " --paths .\\mp3 \"" + url + "\"";

    std::cout << "Processando e baixando o áudio...\n";

    // Execução do comando
    int resultado = std::system(comando.c_str());

    //Somente caso dê erro possa ler.
    std::system("pause");

    // PADRÃO
    if (resultado == 0) {
        std::cout << "CONCLUIDO! Verifique o diretório.\n";
    } else {
        std::cout << "ERRO! Não foi possível baixar o arquivo, tente novamente.\n";
    }

    return 0;
}

//@eduzp//
//lembrando é necessário o uso do yt-dlp e ffmpeg, inclusos no projeto. Não mude o diretório dos arquivos.
//Se for atrás você consegue fazer em Python, ele possuí biblioteca do ffmpeg e yt-dlp integradas que fazem o processo automático.
//Futuramente talvez mude pra C# e adicione GUI neste código.
//Talvez adicione multifunções como mp4 e o download de outras plataformas(sociais).
