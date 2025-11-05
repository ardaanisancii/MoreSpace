#include <iostream>
#include <string>
#include <filesystem>
using namespace std;
namespace fs = std::filesystem;


int main() {

	string klasoryolu = "C:\\Windows\\Temp";
	string klasoryolu2 = "C:\\Windows\\Prefetch";
	string klasoryolu3 = "C:\\Users\\kknsz\\AppData\\Local\\Temp";
	string klasoryolu4 = "C:\\Windows\\SoftwareDistribution\\Download";
	string klasoryolu5 = "C:\\Users\\kknsz\\AppData\\Local\\NVIDIA\\GLCache";

	string klasoryollarý[] = { klasoryolu, klasoryolu2, klasoryolu3, klasoryolu4, klasoryolu5 };

	int toplamsilinen = 0;
	int silinemeyen = 0;

	cout << "--- MoreSpace ---" << endl << endl;
	cout << "Bu uygulama bilgisayarinizda ki kullanilmayan ama bir sure sonra cok yer kaplayan artik dosyalari temizleyerek size yer kazandirir... " << endl << endl;
	for (const auto& yol : klasoryollarý) {
		if (!fs::exists(yol)) {
			cout << "klasor yolu bulunamadi... " << yol << endl;
			continue;

		}
		cout << "Temizleniyor: " << yol << endl;

		for (const auto& entry : fs::directory_iterator(yol)) {

			try {
				toplamsilinen += fs::remove_all(entry.path());
			}
			catch (const exception& e) {
				silinemeyen++;
			}
		}
	}
	cout << "\nIslem tamamlandi! Toplam silinen dosya/klasor: " << toplamsilinen << endl;
	cout << "Silinemeyen dosya sayisi: " << silinemeyen << endl;
	system("pause");
	return 0;

}