#pragma once

#include <string>


// ���� ��������� ������
struct commands_struct {
	static constexpr const char* Method				 = "METHOD";
	static constexpr const char* Product_Affiliation = "PRODUCT_AFFILIATION";
	static constexpr const char* Product_Type		 = "PRODUCT_TYPE";
} commands;


// ������� ������
struct methods_struct { 
	static constexpr const char* Get    = "GET";
	static constexpr const char* Post   = "POST";
	static constexpr const char* Put    = "PUT";
	static constexpr const char* Delete = "DELETE";
	static constexpr const char* Login  = "LOGIN";
	static constexpr const char* Logout = "LOGOUT";
} methods;


// �������������� ���������
struct products_affiliation_struct {
	static constexpr const char* Bicycles	= "BICYCLES";
	static constexpr const char* Skis		= "SKIS";
	static constexpr const char* Roller_Skis = "ROLLER_SKIS";
} products_affiliation;


// ���� ���������
struct product_type_struct {
	static constexpr const char* Shoes		= "SHOES";
	static constexpr const char* Bicycles	= "BICYCLES";
	static constexpr const char* Skis		= "SKIS";
	static constexpr const char* Roller_Skis = "ROLLER_SKIS";
} product_type;


// ����� �������������� ���������
struct product_characteristics {
	static constexpr const char* Firm = "FIRM";
	static constexpr const char* Color = "COLOR";
	static constexpr const char* Price = "PRICE";
	static constexpr const char* Created_At = "CREATED_AT";
	static constexpr const char* Updated_At = "UPDATED_AT";
	static constexpr const char* Description = "DESCRIPTION";
};


// �������������� �������������� �����
struct shoes_characteristics : product_characteristics {
	static constexpr const char* Size = "SIZE";
	static constexpr const char* Material = "MATERIAL";
};


// �������������� �������������� �����������
struct bicycles_characteristics : product_characteristics {
	static constexpr const char* Wheels_Size = "WHEELS_SIZE";
	static constexpr const char* Frame_Size = "FRAME_SIZE";
	static constexpr const char* Material = "MATERIAL";
};


// �������������� �������������� ���
struct skis_characteristics : product_characteristics {
	static constexpr const char* Size = "SIZE";
	static constexpr const char* Skiing_Style = "SKIING_STYLE";
};


// �������������� �������������� ������������
struct roller_skis_characteristics : product_characteristics {
	static constexpr const char* Size = "SIZE";
	static constexpr const char* Skiing_Style = "SKIING_STYLE";
};


