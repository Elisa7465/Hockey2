// Header.h
#include "src/pugixml.hpp"
#include <Windows.h>
#include <conio.h>
#include <vcclr.h>
using namespace pugi;
using namespace System;
using namespace System::IO;
using namespace System::Windows::Forms;
using namespace System::Drawing;
using namespace System::Collections::Generic;
using namespace System::Xml;
interface class GraphicDraw {
public:
    virtual void Draw(Graphics^ g) = 0;
};
ref class GraphicElement {
public:
    Bitmap^ merge;
    Point coordinates;
    Point arrowStart;
    Point arrowEnd;
};
ref class BluePlayer : public GraphicElement, public GraphicDraw {
public:
    BluePlayer(Point coordinates) {
        this->coordinates = coordinates;
        merge = gcnew Bitmap("C:/Users/ed573/Downloads/pngwing.com (1) (1).png");
        merge = gcnew Bitmap(merge, merge->Width / 13, merge->Height / 13);
    }
    virtual void Draw(Graphics^ g) {
        g->DrawImage(merge, coordinates.X, coordinates.Y);
    }
};
ref class RedPlayer : public GraphicElement, public GraphicDraw {
public:
    RedPlayer(Point coordinates) {
        this->coordinates = coordinates;
        merge = gcnew Bitmap("C:/Users/ed573/Downloads/pngwing.com (2).png");
        merge = gcnew Bitmap(merge, merge->Width / 13, merge->Height / 13);
    }
    virtual void Draw(Graphics^ g) {
        g->DrawImage(merge, coordinates.X, coordinates.Y);
    }
};
ref class Arrow : public GraphicElement {
public:
    Arrow() {
    }
    Arrow(Point Start, Point End) {
        arrowStart = Start;
        arrowEnd = End;
    }
    void DrawElement(Graphics^ g) {

        double angle = Math::Atan2(arrowEnd.Y - arrowStart.Y, arrowEnd.X - arrowStart.X);
        double arrowAngle = Math::PI / 8; // ���� ������� ����������� ������������ �������
        double arrowLength = 15.0; // ����� ����������� �������

        // ���������� ����������� �������
        Point^ arrowPoint1 = gcnew Point(arrowEnd.X - (int)(arrowLength * Math::Cos(angle - arrowAngle)), arrowEnd.Y - (int)(arrowLength * Math::Sin(angle - arrowAngle)));
        Point^ arrowPoint2 = gcnew Point(arrowEnd.X - (int)(arrowLength * Math::Cos(angle + arrowAngle)), arrowEnd.Y - (int)(arrowLength * Math::Sin(angle + arrowAngle)));

        // ������ �������
        Pen^ customPen = gcnew Pen(System::Drawing::Color::DarkSlateGray, 3);
        g->DrawLine(customPen, arrowStart.X, arrowStart.Y, arrowEnd.X, arrowEnd.Y);
        g->DrawLine(customPen, arrowEnd.X, arrowEnd.Y, arrowPoint1->X, arrowPoint1->Y);
        g->DrawLine(customPen, arrowEnd.X, arrowEnd.Y, arrowPoint2->X, arrowPoint2->Y);
    }
};
ref class IceRink : public GraphicElement {
public:
    System::Windows::Forms::PictureBox^ ice_rink;
    List<Arrow^>^ arrows; // �������� �������
    int countArrows; // ���������� �������
    List<BluePlayer^>^ bluePlayers;
    List<RedPlayer^>^ redPlayers;
    List<GraphicElement^>^ graphicElements;

    IceRink(System::Windows::Forms::PictureBox^ ice_rink) {
        countArrows = 0;
        arrows = gcnew List<Arrow^>(0);
        this->ice_rink = ice_rink;
        merge = gcnew Bitmap("C:/Users/ed573/Downloads/GQgHvVKv1Fk.jpg");
        graphicElements = gcnew List<GraphicElement^>();
        bluePlayers = gcnew List<BluePlayer^>();
        redPlayers = gcnew List<RedPlayer^>();
    }
    List<GraphicElement^>^ getgraphicElements() {
        return graphicElements;
    }
    void deletePlayer(Point playerCoordinates) {
        for (int i = 0; i < graphicElements->Count; i++) {
            if (playerCoordinates == graphicElements[i]->coordinates) {
                graphicElements->Remove(graphicElements[i]);
                break;
            }
        }
        for (int i = 0; i < redPlayers->Count; i++) {
            if (playerCoordinates == redPlayers[i]->coordinates) {
                redPlayers->Remove(redPlayers[i]);
                break;
            }
        }
        for (int i = 0; i < bluePlayers->Count; i++) {
            if (playerCoordinates == bluePlayers[i]->coordinates) {
                bluePlayers->Remove(bluePlayers[i]);
                break;
            }
        }
        Draw();
    }
    void AddBluePlayer(Point playerCoordinates) {
        if (bluePlayers->Count < 6) {
            BluePlayer^ bluePlayer = gcnew BluePlayer(playerCoordinates);
            bluePlayers->Add(bluePlayer);
            graphicElements->Add(bluePlayer);
        }
        else {
            MessageBox::Show("�� ���� �� ����� ���� ������ 6 ������� �� ����� �����-��");
        }
    }

    void AddRedPlayer(Point playerCoordinates) {
        if (redPlayers->Count < 6) {
            RedPlayer^ redPlayer = gcnew RedPlayer(playerCoordinates);
            redPlayers->Add(redPlayer);
            graphicElements->Add(redPlayer);
        }
        else {
            MessageBox::Show("�� ���� �� ����� ���� ������ 6 ������� �� ������� �����-��");
        }
    }
    void AddArrow(Arrow^ newArrow) {// ���������� �������
        arrows->Add(newArrow);
        graphicElements->Add(newArrow);
    }
    void DeleteArrow() { // �������� �������
        arrows->RemoveAt(countArrows - 1);
        countArrows -= 1;
    }
    void Draw() {
        if (ice_rink != nullptr) {
            // ��������� �����
            Graphics^ g = ice_rink->CreateGraphics();
            g->DrawImage(merge, 0, 0);
            // ��������� �������
            for (int i = 0; i < graphicElements->Count; i++) {
                // �������� ���� �������� � ����� ��������������� ������� Draw
                BluePlayer^ bluePlayer = dynamic_cast<BluePlayer^>(graphicElements[i]);
                if (bluePlayer != nullptr) {
                    bluePlayer->Draw(g);
                    continue;
                }

                RedPlayer^ redPlayer = dynamic_cast<RedPlayer^>(graphicElements[i]);
                if (redPlayer != nullptr) {
                    redPlayer->Draw(g);
                    continue;
                }
                Arrow^ arrow = dynamic_cast<Arrow^>(graphicElements[i]);
                if (arrow != nullptr) {
                    arrow->DrawElement(g);
                    continue;
                }
            }

            delete g;
        }
    }
    void savexml() {
        pugi::xml_document doc;
        // ������� �������� �������
        pugi::xml_node root = doc.append_child("IceRink");
        // ��������� ������ � ������ ����� ������
        for (int i = 0; i < bluePlayers->Count; ++i) {
            BluePlayer^ bluePlayer = bluePlayers[i];
            pugi::xml_node playerNode = root.append_child("BluePlayer");
            playerNode.append_attribute("X").set_value(bluePlayer->coordinates.X);
            playerNode.append_attribute("Y").set_value(bluePlayer->coordinates.Y);
        }
        // ��������� ������ � ������ ������� ������
        for (int i = 0; i < redPlayers->Count; ++i) {
            RedPlayer^ redPlayer = redPlayers[i];
            pugi::xml_node playerNode = root.append_child("RedPlayer");
            playerNode.append_attribute("X").set_value(redPlayer->coordinates.X);
            playerNode.append_attribute("Y").set_value(redPlayer->coordinates.Y);
            // �������� ������ �������� ��� ������, ������� �� ������ ���������
        }
        try
        {
            doc.save_file("IceRinkData.xml");

        }
        catch (Exception^ ex)
        {
            MessageBox::Show("������ ���������� � ����: " + ex->Message);
        }
    }
    void loadxml() {
        pugi::xml_document doc;
        // ��������� XML-�������� �� �����
        if (!doc.load_file("IceRinkData.xml")) {
            // ���� �������� �� �������, ������� ��������� �� ������
            MessageBox::Show("������ �������� XML �����.", "������", MessageBoxButtons::OK, MessageBoxIcon::Error);
            return;
        }
        // ������� ������ ������� � ���������
        bluePlayers->Clear();
        redPlayers->Clear();
        graphicElements->Clear();
        // �������� �������� �������
        pugi::xml_node root = doc.child("IceRink");
        // ��������� ������ � ����� �������
        for (pugi::xml_node playerNode = root.child("BluePlayer"); playerNode; playerNode = playerNode.next_sibling("BluePlayer")) {
            int x = playerNode.attribute("X").as_int();
            int y = playerNode.attribute("Y").as_int();
            AddBluePlayer(Point(x, y));
        }
        // ��������� ������ � ������� �������
        for (pugi::xml_node playerNode = root.child("RedPlayer"); playerNode; playerNode = playerNode.next_sibling("RedPlayer")) {
            int x = playerNode.attribute("X").as_int();
            int y = playerNode.attribute("Y").as_int();
            AddRedPlayer(Point(x, y));
        }
        // ������������ ����������� ������
        Draw();
        // ������� ��������� �� �������� ��������
        MessageBox::Show("������ ������� ��������� �� XML �����.", "�����", MessageBoxButtons::OK, MessageBoxIcon::Information);
    }
};



