#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>
#include <filesystem>
#include <cstdlib>

using namespace std;
namespace fs = std::filesystem;

int main() {

    // Kullanýcý baðýmsýz yollar
    string userProfile = getenv("USERPROFILE"); // Örn: C:\Users\Ahmet
    string localAppData = userProfile + "\\AppData\\Local";

    string klasoryolu1 = "C:\\Windows\\Temp";
    string klasoryolu2 = "C:\\Windows\\Prefetch";
    string klasoryolu3 = localAppData + "\\Temp";
    string klasoryolu4 = "C:\\Windows\\SoftwareDistribution\\Download";
    string klasoryolu5 = localAppData + "\\NVIDIA\\GLCache";

    string klasoryollari[] = { klasoryolu1, klasoryolu2, klasoryolu3, klasoryolu4, klasoryolu5 };

    int toplamsilinen = 0;
    int silinemeyen = 0;

    cout << "--- MoreSpace ---" << endl << endl;
    cout << "Bu uygulama bilgisayardaki gecici ve gereksiz artik dosyalari temizleyerek yer kazandirir." << endl << endl;

    for (const auto& yol : klasoryollari) {

        if (!fs::exists(yol)) {
            cout << "Klasor yolu bulunamadi: " << yol << endl;
            continue;
        }

        cout << "Temizleniyor: " << yol << endl;

        for (const auto& entry : fs::directory_iterator(yol)) {
            try {
                toplamsilinen += fs::remove_all(entry.path());
            }
            catch (...) {
                silinemeyen++;
            }
        }
    }

    cout << "\nIslem tamamlandi!" << endl;
    cout << "Toplam silinen dosya/klasor: " << toplamsilinen << endl;
    cout << "Silinemeyen dosya sayisi: " << silinemeyen << endl;

    system("pause");
    return 0;
}
