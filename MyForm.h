
#pragma once
#include "Header.h"

namespace Hockey2 {

    using namespace System;
    using namespace System::Windows::Forms;
    using namespace System::Drawing;
    public ref class MyForm : public System::Windows::Forms::Form
    {
    public:
        MyForm()
        {
            InitializeComponent();
            InitializeGame();
        }

    protected:
        ~MyForm()
        {
            if (components)
            {
                delete components;
            }
        }
    private: System::ComponentModel::IContainer^ components;
    protected:
    private:System::Windows::Forms::Button^ buttonAddBluePlayer;
    private: System::Windows::Forms::PictureBox^ pictureBox1;// PictureBox для отображения игрового поля
    private: System::Windows::Forms::Button^ Addredplayer;
    private: System::Windows::Forms::MenuStrip^ menuStrip1;
    private: System::Windows::Forms::ToolStripMenuItem^ файлToolStripMenuItem;
    private: System::Windows::Forms::ToolStripMenuItem^ сохранитьToolStripMenuItem;
    private: System::Windows::Forms::ToolStripMenuItem^ загрToolStripMenuItem;
    private: System::Windows::Forms::OpenFileDialog^ openFileDialog1;
    private: System::Windows::Forms::Button^ button1;
    private: System::Windows::Forms::SaveFileDialog^ saveFileDialog1;
    private: System::Windows::Forms::Button^ button2;
    private: System::Windows::Forms::Button^ button3;
           Arrow^ newArrow;
           List<Arrow^>^ arrows;
    private: System::Windows::Forms::Button^ button4;
         // Объект катка
    private: IceRink^ iceRink;
           // Инициализация игровых элементов
           void InitializeGame()
           {
               newArrow = gcnew Arrow();
               // Создание объекта катка
               iceRink = gcnew IceRink(pictureBox1);

               iceRink->Draw();
           }
           // Обработчик события клика на "Моя стрелка"
#pragma region Windows Form Designer generated code
           void InitializeComponent(void)
           {
               this->pictureBox1 = (gcnew System::Windows::Forms::PictureBox());
               this->buttonAddBluePlayer = (gcnew System::Windows::Forms::Button());
               this->Addredplayer = (gcnew System::Windows::Forms::Button());
               this->menuStrip1 = (gcnew System::Windows::Forms::MenuStrip());
               this->файлToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
               this->сохранитьToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
               this->загрToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
               this->openFileDialog1 = (gcnew System::Windows::Forms::OpenFileDialog());
               this->button1 = (gcnew System::Windows::Forms::Button());
               this->saveFileDialog1 = (gcnew System::Windows::Forms::SaveFileDialog());
               this->button2 = (gcnew System::Windows::Forms::Button());
               this->button3 = (gcnew System::Windows::Forms::Button());
               this->button4 = (gcnew System::Windows::Forms::Button());
               (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->BeginInit();
               this->menuStrip1->SuspendLayout();
               this->SuspendLayout();
               // 
               // pictureBox1
               // 
               this->pictureBox1->BackColor = System::Drawing::Color::White;
               this->pictureBox1->Location = System::Drawing::Point(12, 27);
               this->pictureBox1->Name = L"pictureBox1";
               this->pictureBox1->Size = System::Drawing::Size(1200, 558);
               this->pictureBox1->TabIndex = 0;
               this->pictureBox1->TabStop = false;
               this->pictureBox1->DoubleClick += gcnew System::EventHandler(this, &MyForm::pictureBox1_DoubleClick);
               this->pictureBox1->MouseDown += gcnew System::Windows::Forms::MouseEventHandler(this, &MyForm::pictureBox1_MouseDown);
               this->pictureBox1->MouseMove += gcnew System::Windows::Forms::MouseEventHandler(this, &MyForm::pictureBox1_MouseMove);
               this->pictureBox1->MouseUp += gcnew System::Windows::Forms::MouseEventHandler(this, &MyForm::pictureBox1_MouseUp);
               // 
               // buttonAddBluePlayer
               // 
               this->buttonAddBluePlayer->BackColor = System::Drawing::Color::SkyBlue;
               this->buttonAddBluePlayer->Location = System::Drawing::Point(1228, 40);
               this->buttonAddBluePlayer->Name = L"buttonAddBluePlayer";
               this->buttonAddBluePlayer->Size = System::Drawing::Size(181, 76);
               this->buttonAddBluePlayer->TabIndex = 1;
               this->buttonAddBluePlayer->Text = L"Добавить синего хоккеиста";
               this->buttonAddBluePlayer->UseVisualStyleBackColor = false;
               this->buttonAddBluePlayer->Click += gcnew System::EventHandler(this, &MyForm::buttonAddBluePlayer_Click);
               // 
               // Addredplayer
               // 
               this->Addredplayer->BackColor = System::Drawing::Color::Tomato;
               this->Addredplayer->Location = System::Drawing::Point(1228, 133);
               this->Addredplayer->Name = L"Addredplayer";
               this->Addredplayer->Size = System::Drawing::Size(181, 69);
               this->Addredplayer->TabIndex = 2;
               this->Addredplayer->Text = L"Добавить красного хоккеиста";
               this->Addredplayer->UseVisualStyleBackColor = false;
               this->Addredplayer->Click += gcnew System::EventHandler(this, &MyForm::buttonAddRedPlayer_Click);
               // 
               // menuStrip1
               // 
               this->menuStrip1->ImageScalingSize = System::Drawing::Size(20, 20);
               this->menuStrip1->Items->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(1) { this->файлToolStripMenuItem });
               this->menuStrip1->Location = System::Drawing::Point(0, 0);
               this->menuStrip1->Name = L"menuStrip1";
               this->menuStrip1->Size = System::Drawing::Size(1421, 28);
               this->menuStrip1->TabIndex = 3;
               this->menuStrip1->Text = L"menuStrip1";
               // 
               // файлToolStripMenuItem
               // 
               this->файлToolStripMenuItem->DropDownItems->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(2) {
                   this->сохранитьToolStripMenuItem,
                       this->загрToolStripMenuItem
               });
               this->файлToolStripMenuItem->Name = L"файлToolStripMenuItem";
               this->файлToolStripMenuItem->Size = System::Drawing::Size(59, 24);
               this->файлToolStripMenuItem->Text = L"Файл";
               // 
               // сохранитьToolStripMenuItem
               // 
               this->сохранитьToolStripMenuItem->Name = L"сохранитьToolStripMenuItem";
               this->сохранитьToolStripMenuItem->Size = System::Drawing::Size(166, 26);
               this->сохранитьToolStripMenuItem->Text = L"Сохранить";
               this->сохранитьToolStripMenuItem->Click += gcnew System::EventHandler(this, &MyForm::SaveToXML_Click);
               // 
               // загрToolStripMenuItem
               // 
               this->загрToolStripMenuItem->Name = L"загрToolStripMenuItem";
               this->загрToolStripMenuItem->Size = System::Drawing::Size(166, 26);
               this->загрToolStripMenuItem->Text = L"Загрузить";
               this->загрToolStripMenuItem->Click += gcnew System::EventHandler(this, &MyForm::LoadXML_Click);
               // 
               // openFileDialog1
               // 
               this->openFileDialog1->FileName = L"openFileDialog1";
               // 
               // button1
               // 
               this->button1->BackColor = System::Drawing::Color::LemonChiffon;
               this->button1->Location = System::Drawing::Point(1228, 220);
               this->button1->Name = L"button1";
               this->button1->Size = System::Drawing::Size(181, 65);
               this->button1->TabIndex = 4;
               this->button1->Text = L"Сохранить в xml";
               this->button1->UseVisualStyleBackColor = false;
               this->button1->Click += gcnew System::EventHandler(this, &MyForm::SaveToXML_Click);
               // 
               // button2
               // 
               this->button2->BackColor = System::Drawing::Color::LemonChiffon;
               this->button2->Location = System::Drawing::Point(1228, 302);
               this->button2->Name = L"button2";
               this->button2->Size = System::Drawing::Size(181, 65);
               this->button2->TabIndex = 5;
               this->button2->Text = L"Загрузить из xml";
               this->button2->UseVisualStyleBackColor = false;
               this->button2->Click += gcnew System::EventHandler(this, &MyForm::LoadXML_Click);
               // 
               // button3
               // 
               this->button3->Location = System::Drawing::Point(1228, 385);
               this->button3->Name = L"button3";
               this->button3->Size = System::Drawing::Size(181, 65);
               this->button3->TabIndex = 6;
               this->button3->Text = L"Добавить стрелку";
               this->button3->UseVisualStyleBackColor = true;
               this->button3->Click += gcnew System::EventHandler(this, &MyForm::buttonDrawArrow_Click);
               // 
               // button4
               // 
               this->button4->Location = System::Drawing::Point(1228, 465);
               this->button4->Name = L"button4";
               this->button4->Size = System::Drawing::Size(181, 65);
               this->button4->TabIndex = 7;
               this->button4->Text = L"Удалить стрелку";
               this->button4->UseVisualStyleBackColor = true;
               this->button4->Click += gcnew System::EventHandler(this, &MyForm::delarrowToolStripMenuItem_Click);
               // 
               // MyForm
               // 
               this->BackColor = System::Drawing::SystemColors::InactiveCaption;
               this->ClientSize = System::Drawing::Size(1421, 641);
               this->Controls->Add(this->button4);
               this->Controls->Add(this->button3);
               this->Controls->Add(this->button2);
               this->Controls->Add(this->button1);
               this->Controls->Add(this->Addredplayer);
               this->Controls->Add(this->buttonAddBluePlayer);
               this->Controls->Add(this->pictureBox1);
               this->Controls->Add(this->menuStrip1);
               this->DoubleBuffered = true;
               this->MainMenuStrip = this->menuStrip1;
               this->Name = L"MyForm";
               this->Text = L"Hockey";
               (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->EndInit();
               this->menuStrip1->ResumeLayout(false);
               this->menuStrip1->PerformLayout();
               this->ResumeLayout(false);
               this->PerformLayout();

           }
#pragma endregion

           // Переменные для отслеживания состояния перетаскивания
           bool isDragging;
           int draggedImageIndex;
           Point offset;
           bool start;

           // Обработчик события нажатия кнопки мыши
           System::Void pictureBox1_MouseDown(System::Object^ sender, System::Windows::Forms::MouseEventArgs^ e) {
               isDragging = false;
               // Проверка, попадает ли точка нажатия в какое-либо изображение
               List<GraphicElement^>^ elements = iceRink->getgraphicElements();
               for (int i = 0; i < elements->Count; i++)
               {
                   Arrow^ arrow = dynamic_cast<Arrow^>(elements[i]);

                   if (elements[i]->merge != nullptr) {
                       System::Drawing::Rectangle imageRect = System::Drawing::Rectangle(Point(elements[i]->coordinates.X, elements[i]->coordinates.Y), elements[i]->merge->Size);
                       // Ваш код
                       if (imageRect.Contains(e->Location))
                       {
                           isDragging = true;
                           draggedImageIndex = i;
                           offset = Point(e->Location.X - elements[i]->coordinates.X, e->Location.Y - elements[i]->coordinates.Y);
                           break;
                       }
                   }
                   if (arrow != nullptr) {
                       System::Drawing::Rectangle imageRect = System::Drawing::Rectangle(arrow->arrowStart.X - 5, arrow->arrowStart.Y - 5, 10, 10);
                       if (imageRect.Contains(e->Location))
                       {
                           start = 1;
                           isDragging = true;
                           draggedImageIndex = i;
                           offset = Point(e->Location.X - arrow->arrowStart.X, e->Location.Y - arrow->arrowStart.Y);
                           break;
                       }
                       imageRect = System::Drawing::Rectangle(arrow->arrowEnd.X - 5, arrow->arrowEnd.Y - 5, 10, 10);
                       if (imageRect.Contains(e->Location))
                       {
                           start = 0;
                           isDragging = true;
                           draggedImageIndex = i;
                           offset = Point(e->Location.X - arrow->arrowEnd.X, e->Location.Y - arrow->arrowEnd.Y);
                           break;
                       }
                   }

               }
           }
           // Обработчик события перемещения мыши
           System::Void pictureBox1_MouseMove(System::Object^ sender, System::Windows::Forms::MouseEventArgs^ e) {
               if (isDragging) {
                   List<GraphicElement^>^ elements = iceRink->getgraphicElements();
                   if (draggedImageIndex >= 0 && draggedImageIndex < elements->Count) {
                       Arrow^ arrow = dynamic_cast<Arrow^>(elements[draggedImageIndex]);
                       if (arrow != nullptr) {
                           if (start) {
                               elements[draggedImageIndex]->arrowStart = Point(e->X - offset.X, e->Y - offset.Y);
                               iceRink->Draw();
                           }
                           else {
                               elements[draggedImageIndex]->arrowEnd = Point(e->X - offset.X, e->Y - offset.Y);
                               iceRink->Draw();
                           }
                       }
                       else {
                           elements[draggedImageIndex]->coordinates = Point(e->X - offset.X, e->Y - offset.Y);
                           iceRink->Draw();
                       }
                   }
               }
           }

           System::Void buttonAddBluePlayer_Click(System::Object^ sender, System::EventArgs^ e)
           {
               iceRink->AddBluePlayer(Point(200, 200)); // Измените координаты при необходимости
               iceRink->Draw(); // Перерисовка формы
           }
           System::Void buttonAddRedPlayer_Click(System::Object^ sender, System::EventArgs^ e) {
               iceRink->AddRedPlayer(Point(200, 200)); // Измените координаты при необходимости
               iceRink->Draw(); // Перерисовка формы
           }
           System::Void pictureBox1_DoubleClick(System::Object^ sender, System::EventArgs^ e) {
               List<GraphicElement^>^ elements = iceRink->getgraphicElements();
               for (int i = 0; i < elements->Count; i++)
               {
                   System::Drawing::Rectangle imageRect = System::Drawing::Rectangle(Point(elements[i]->coordinates.X, elements[i]->coordinates.Y), elements[i]->merge->Size);

                   if (imageRect.Contains(PointToClient(MousePosition)))
                   {
                       iceRink->deletePlayer(elements[i]->coordinates);
                   }
               }
               iceRink->Draw(); // Перерисовка формы
           }
           //Сохранение в XML
    private: System::Void SaveToXML_Click(System::Object^ sender, System::EventArgs^ e) {
        saveFileDialog1->Filter = "xml (*.xml)|*.xml|All files(*.*)|*.*";
        // Диалоговое окно для сохранения файла
        if (saveFileDialog1->ShowDialog() == System::Windows::Forms::DialogResult::OK) {
            // Получаем путь к выбранному файлу
            String^ filePath = saveFileDialog1->FileName;

            // Создаем объект IceRink (если его еще нет)
            if (iceRink == nullptr) {
                iceRink = gcnew IceRink(pictureBox1);
            }
            // Вызываем функцию сохранения в XML
            iceRink->savexml();
            // Выводим сообщение об успешном сохранении
            MessageBox::Show("Данные успешно сохранены в XML файл.", "Успех", MessageBoxButtons::OK, MessageBoxIcon::Information);
        }
    }
           //Загрузка из XML
    private: System::Void LoadXML_Click(System::Object^ sender, System::EventArgs^ e) {
        pugi::xml_document doc;
        openFileDialog1->Filter = "xml (*.xml)|*.xml|All files(*.*)|*.*";
        if (openFileDialog1->ShowDialog() == System::Windows::Forms::DialogResult::OK) {
            iceRink->loadxml();
        }
    }
    private: System::Void delarrowToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e) {
        if (iceRink->countArrows > 0) {
            iceRink->DeleteArrow();
            iceRink->Draw();
        }
    }
    private: System::Void buttonDrawArrow_Click(System::Object^ sender, System::EventArgs^ e) {
        // Добавьте стрелку при нажатии кнопки
        iceRink->AddArrow(gcnew Arrow(Point(100, 100), Point(150, 150)));
        iceRink->Draw();
    }
    private: System::Void pictureBox1_MouseUp(System::Object^ sender, System::Windows::Forms::MouseEventArgs^ e) {
        isDragging = false;
    }
    };
}



