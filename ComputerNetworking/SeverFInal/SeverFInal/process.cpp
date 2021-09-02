//
//
//static size_t WriteCallback(void* contents, size_t size, size_t nmemb, void* userp)
//{
//	((string*)userp)->append((char*)contents, size * nmemb);
//	return size * nmemb;
//}
//void cleanData(string data, string name, TIENTE& t)
//{
//	t.ten = name;
//	size_t distance1 = data.find(name) + 27;
//	size_t pos1 = data.find(">", distance1 - 2);
//	size_t pos2 = data.find("<", pos1);
//	size_t numberOfDigit = pos2 - pos1 - 1;
//	t.tyGiaTT = data.substr(distance1, numberOfDigit);
//
//	distance1 = distance1 + numberOfDigit + 24;
//	pos1 = data.find(">", distance1 - 2);
//	pos2 = data.find("<", pos1);
//	numberOfDigit = pos2 - pos1 - 1;
//	t.tyGiaMua.tienMat = data.substr(distance1, numberOfDigit);
//
//	distance1 = distance1 + numberOfDigit + 24;
//	pos1 = data.find(">", distance1 - 2);
//	pos2 = data.find("<", pos1);
//	numberOfDigit = pos2 - pos1 - 1;
//	t.tyGiaMua.chuyenKhoan = data.substr(distance1, numberOfDigit);
//
//	distance1 = distance1 + numberOfDigit + 24;
//	pos1 = data.find(">", distance1 - 2);
//	pos2 = data.find("<", pos1);
//	numberOfDigit = pos2 - pos1 - 1;
//	t.tyGiaBan = data.substr(distance1, numberOfDigit);
//
//	if (name == "EUR")
//	{
//		distance1 = distance1 + numberOfDigit + 98;
//		pos1 = data.find(">", distance1 - 2);
//		pos2 = data.find("<", pos1);
//		numberOfDigit = pos2 - pos1 - 1;
//		t.note = data.substr(distance1, numberOfDigit);
//		distance1 = distance1 + numberOfDigit + 24;
//	}
//	if (name == "USD")
//	{
//		distance1 = distance1 + numberOfDigit + 97;
//		pos1 = data.find(">", distance1 - 2);
//		pos2 = data.find("<", pos1);
//		numberOfDigit = pos2 - pos1 - 1;
//		t.note = data.substr(distance1, numberOfDigit);
//		distance1 = distance1 + numberOfDigit + 24;
//	}
//}
//string processDate(string data)
//{
//	size_t pos1 = data.find("lúc");
//	size_t pos2 = data.find("và chỉ mang");
//	string inforDate = data.substr(pos1 + 5, pos2 - pos1 - 1);
//	return inforDate;
//}