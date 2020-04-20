// Vigenere.cpp : Este archivo contiene la función "main". La ejecución del programa comienza y termina ahí.
//

#include <iostream>
#include <string>
#include "VigenereE.h"
#include "Kasiski.h"
#include "Vigener.h"
using namespace std;

void divisioneneros(int a ,int n) {
    int q, r;
    q = a / n;
    r = a - q*n;
    a = q;
    n = r;
    cout << "q " << q << " r " << r<<endl;
    while (a>0) {
        q = a / n;
        r = a - q * n;
        a = q;
        n = r;
        cout << "q " << q << " r " << r << endl;
    }
 
}





int main()
{
    
//divisioneneros(1003,107);
   /* VigenereE desc("Pablo Neruda");*/
    string mensaje = "Lorem ipsum dolor sit amet, consectetur adipiscing elit. Maecenas quis nulla at ligula aliquet elementum sit amet sit amet est. Aliquam ac augue lorem. Curabitur ut viverra velit, nec efficitur nibh. Cras ac diam elementum, lacinia eros vel, iaculis lacus. Cras lacinia lectus ut luctus fringilla. Pellentesque risus erat, varius sit amet velit ut, tempor congue dui. Ut sit amet tristique eros. Etiam malesuada ante ex, eget vulputate nisi tincidunt quis. Nulla facilisi. Maecenas euismod mi a lacinia aliquam. Suspendisse non vestibulum urna, id suscipit sem. Donec libero risus, sodales a laoreet nec, maximus nec odio. Pellentesque turpis eros, convallis fringilla varius eget, laoreet et nisi. Aliquam et sem nunc.Ut convallis libero id libero laoreet, id ultrices urna condimentum. Etiam lorem lorem, condimentum et pulvinar sed, aliquam eu quam. Praesent sit amet metus id arcu hendrerit ornare ac sit amet nulla. Sed congue vel magna eu convallis. Donec blandit sem ut luctus semper. Cras condimentum quam vel massa consequat, vel ultricies mi cursus. Sed sed nibh id purus tincidunt bibendum quis a enim.Etiam dui turpis, consectetur lacinia vulputate at, scelerisque sit amet odio. Sed fringilla condimentum libero, vitae pulvinar orci sagittis sit amet. Vivamus euismod orci sed mauris convallis volutpat. Pellentesque pharetra bibendum ante, ac laoreet dui malesuada sit amet. Nulla id mauris quis leo finibus bibendum sit amet vel dui. Integer scelerisque luctus massa, congue mollis sem fringilla sit amet. Aliquam eget hendrerit nibh. Quisque est lectus, suscipit eu aliquet quis, tempus in sapien. Maecenas convallis sagittis enim, quis tincidunt felis. Suspendisse non nulla hendrerit, laoreet nunc eu, dictum quam. Nunc vitae lectus a dui ornare varius at non nisi. Duis id purus et quam porttitor cursus sit amet non magna. Ut cursus id magna a viverra.Ut egestas faucibus eros eget placerat. Vestibulum ante ipsum primis in faucibus orci luctus et ultrices posuere cubilia Curae; Phasellus vitae venenatis eros, vitae aliquet tortor. Donec sagittis vel ipsum eu pulvinar. Nunc aliquam finibus purus. Nulla luctus augue ex, et finibus purus accumsan a. Sed tincidunt leo quis augue elementum ornare. Maecenas vestibulum est eu bibendum feugiat. Pellentesque tempus metus non luctus laoreet.Quisque scelerisque sodales iaculis. Morbi ultrices aliquet leo, vel congue risus aliquam eget. Vivamus ornare imperdiet lectus id rhoncus. Fusce at risus ut orci aliquam posuere sit amet nec ex. Curabitur vitae mauris justo. Aliquam erat volutpat. Aliquam vehicula risus ac arcu luctus aliquet. Curabitur faucibus iaculis laoreet. Phasellus suscipit egestas justo in vehicula. Fusce at nulla aliquet, aliquet lectus eu, lacinia orci. Pellentesque habitant morbi tristique senectus et netus et malesuada fames ac turpis egestas. Nam eu condimentum sapien, et placerat nisi. Sed eget ultrices est, eget varius orci. Suspendisse molestie massa dolor, nec condimentum lectus pellentesque luctus. Maecenas turpis nulla, tincidunt at molestie id, posuere elementum diam.Maecenas sed nisi fringilla libero faucibus pulvinar. Donec eu varius lectus. Quisque a purus cursus, malesuada elit a, finibus felis. Duis lacinia sit amet mauris in semper. Aenean varius tempus congue. Maecenas in tortor varius, sagittis elit ut, pretium neque. Nullam convallis, lectus nec placerat varius, nulla dolor elementum nisi, non consequat libero eros et eros. Cras mattis volutpat urna, sit amet lacinia lorem maximus quis. Curabitur sit amet varius lacus, sed porttitor sem. Ut maximus mauris tellus, commodo dapibus mauris maximus sit amet. Morbi tempus sem ac mattis ullamcorper. Aenean lacinia odio et sem rhoncus, vitae porta velit finibus. Sed scelerisque lobortis turpis. Sed blandit elit non interdum dapibus.In mi massa, placerat nec ultricies in, elementum nec magna. Phasellus a egestas nunc, ut vestibulum nulla. Etiam tempus est eros, sed imperdiet tortor dignissim at. Suspendisse ornare porta ipsum nec mattis. Fusce pharetra pulvinar urna, sit amet mattis lectus finibus eu. Praesent vel congue libero, ut tincidunt purus. Ut consectetur dolor sed malesuada porttitor. Nam hendrerit enim dolor, nec dapibus justo euismod id. Nullam vel nibh non massa porttitor mollis. Mauris sit amet tortor consectetur, posuere erat id, sollicitudin diam. In a nunc ligula. Sed sit amet sagittis elit, nec pretium lectus. In venenatis porta tincidunt. Donec laoreet, metus et euismod rhoncus, massa nibh facilisis elit, non pharetra nunc quam at turpis.Integer posuere eros massa, quis congue libero sollicitudin eget. Mauris vel fringilla purus, ut suscipit ligula. Nam pulvinar lorem facilisis, eleifend massa eget, imperdiet justo. Proin quam justo, eleifend nec tempor et, cursus eu mi. Mauris convallis ullamcorper pulvinar. Aenean ac viverra dui, eget ullamcorper lectus. Morbi in augue imperdiet, bibendum magna sit amet, hendrerit libero. Quisque tincidunt sapien eget ligula pharetra dignissim. Nullam finibus felis et elit sollicitudin, id semper lectus placerat. Ut pharetra aliquam posuere. Phasellus pellentesque, sem eget fermentum malesuada, mi ante gravida odio, at elementum quam tortor eget urna. Nulla blandit elit vitae pellentesque viverra. Praesent hendrerit, orci sed ultricies sagittis, tellus tortor auctor neque, non ullamcorper velit ex at magna. Donec euismod augue eu erat accumsan, ultrices varius nulla molestie.Aliquam nec ornare tellus. Proin ut dolor malesuada, condimentum quam quis, gravida felis. Pellentesque ultrices lacus et magna pretium, in sollicitudin tellus tristique. Morbi ullamcorper cursus sem eget volutpat. Donec cursus hendrerit massa vel iaculis. Sed vestibulum est eget massa interdum, id consequat velit venenatis. Morbi vel feugiat enim. Duis pharetra risus vitae sodales malesuada. Aliquam venenatis erat in pellentesque blandit.Donec eget vulputate nisl. Nulla condimentum porttitor erat, id sollicitudin eros tempus at. Pellentesque habitant morbi tristique senectus et netus et malesuada fames ac turpis egestas. Suspendisse eleifend arcu enim, sed pulvinar justo varius at. Nunc placerat porta erat sit amet consectetur. Suspendisse rhoncus auctor eleifend. Proin cursus quis neque eget vulputate. Nam bibendum arcu augue, sit amet posuere ex pretium sodales. Suspendisse potenti.Nunc facilisis nec metus at varius. Nullam erat nisi, varius eu tempus nec, egestas quis risus. Pellentesque id vehicula massa. Integer eleifend congue neque, ac ullamcorper lacus sodales sed. Nam at commodo tortor. Curabitur ac purus metus. Praesent a dapibus lectus. Morbi at ullamcorper sapien, vel laoreet urna. In euismod nec dolor non porta. Vestibulum ante ipsum primis in faucibus orci luctus et ultrices posuere cubilia Curae; Pellentesque turpis turpis, consectetur a lorem nec, malesuada cursus turpis. Nam commodo lectus augue, at rutrum justo rhoncus sit amet. Cras id ultricies dui. Donec elementum augue a nibh tristique pretium. Maecenas eget ligula in nunc porttitor suscipit. Nulla tincidunt turpis eget massa molestie ornare.Nullam dapibus laoreet dolor, nec placerat massa condimentum vel. In aliquam tincidunt nisl, non sagittis urna tempus et. Vestibulum ante ipsum primis in faucibus orci luctus et ultrices posuere cubilia Curae; Etiam consequat at elit nec finibus. Etiam pharetra, justo id tristique efficitur, lacus lectus sagittis eros, eget accumsan augue dui et mi. Cras sed lacus placerat, commodo mauris nec, vestibulum risus. Quisque luctus enim ex, non pulvinar enim molestie ac. Vestibulum id risus hendrerit, euismod nisi vulputate, pharetra mauris. Maecenas vel consequat eros. Donec eu nisl vitae magna tempus posuere. Duis eu nisi quis quam consectetur efficitur in id leo. Sed auctor nunc ex, nec lacinia leo iaculis ac. Vestibulum sed lorem tempor, fermentum tellus eu, lacinia nisl.Morbi luctus nulla quis tempor scelerisque. Donec sit amet tortor velit. Nulla erat ex, rutrum in lectus eget, egestas suscipit diam. Praesent pellentesque purus sollicitudin dui ornare viverra. Morbi bibendum turpis ut blandit porttitor. Aliquam erat volutpat. Donec non dui convallis, euismod sapien eu, porta lectus. Integer nec ex ac tortor pharetra aliquet.Pellentesque tortor lectus, sollicitudin a nisl ut, tincidunt vehicula justo. Vivamus sapien diam, blandit id mauris a, blandit cursus mi. In sit amet convallis ex, sit amet pellentesque tellus. In vehicula justo sed elit feugiat, in consectetur ligula tempor. Etiam sit amet urna sit amet lacus molestie accumsan. In erat neque, facilisis quis nulla ut, semper placerat arcu. Sed viverra ante ac mi porttitor, in lobortis justo tempus. Nunc eu tellus et purus pharetra sodales in ut libero. Proin consectetur dolor libero, a dignissim urna vulputate ac. Ut tristique gravida ornare. Nulla facilisi.Aliquam vel finibus risus, consectetur euismod diam. Vestibulum ante ipsum primis in faucibus orci luctus et ultrices posuere cubilia Curae; Lorem ipsum dolor sit amet, consectetur adipiscing elit. Sed ultrices nulla vel felis dignissim iaculis. Fusce pretium libero at mauris fringilla, at congue elit varius. Curabitur volutpat sodales metus. Fusce sagittis eleifend tincidunt. Morbi quis feugiat ex. Etiam hendrerit lacus id sem tempus, vitae rhoncus metus lacinia. Nunc interdum vitae diam sit amet eleifend. Praesent at magna in risus fringilla condimentum in nec augue. Lorem ipsum dolor sit amet, consectetur adipiscing elit. Nulla a volutpat magna. Praesent venenatis velit a ipsum faucibus mattis. Pellentesque imperdiet interdum iaculis. Aenean interdum urna mauris, eu convallis arcu efficitur non.";
    Vigener codificador("choclo");
    string codifi = codificador.cifrado(mensaje);
   /* string descifa = desc.cifrado(mensaje);
    cout << descifa << endl;
    cout << desc.descifrado(descifa);*/
    Kasiski k;
    k.fill1digitStadistic(codifi);
}

// Ejecutar programa: Ctrl + F5 o menú Depurar > Iniciar sin depurar
// Depurar programa: F5 o menú Depurar > Iniciar depuración

// Sugerencias para primeros pasos: 1. Use la ventana del Explorador de soluciones para agregar y administrar archivos
//   2. Use la ventana de Team Explorer para conectar con el control de código fuente
//   3. Use la ventana de salida para ver la salida de compilación y otros mensajes
//   4. Use la ventana Lista de errores para ver los errores
//   5. Vaya a Proyecto > Agregar nuevo elemento para crear nuevos archivos de código, o a Proyecto > Agregar elemento existente para agregar archivos de código existentes al proyecto
//   6. En el futuro, para volver a abrir este proyecto, vaya a Archivo > Abrir > Proyecto y seleccione el archivo .sln


