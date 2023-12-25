#include "MyForm.h"
#include "Windows.h"
#include <iostream>

using namespace System;
using namespace System::Windows::Forms;

[STAThread]
int main(array<String^>^ arg) {
    Application::EnableVisualStyles();
    Application::SetCompatibleTextRenderingDefault(false);

    Hockey2::MyForm form; //WinFormsTest - имя вашего проекта
    Application::Run(% form);
}


