#pragma once

#include <string>


// рхош днярсомшу йнлюмд
struct commands_struct {
	static constexpr const char* Method				 = "METHOD";
	static constexpr const char* Product_Affiliation = "PRODUCT_AFFILIATION";
	static constexpr const char* Product_Type		 = "PRODUCT_TYPE";
} commands;


// цкюбмше лерндш
struct methods_struct { 
	static constexpr const char* Get    = "GET";
	static constexpr const char* Post   = "POST";
	static constexpr const char* Put    = "PUT";
	static constexpr const char* Delete = "DELETE";
	static constexpr const char* Login  = "LOGIN";
	static constexpr const char* Logout = "LOGOUT";
} methods;


// опхмюдкефмнярх опндсйрнб
struct products_affiliation_struct {
	static constexpr const char* Bicycles	= "BICYCLES";
	static constexpr const char* Skis		= "SKIS";
	static constexpr const char* Roller_Skis = "ROLLER_SKIS";
} products_affiliation;


// рхош опндсйрнб
struct product_type_struct {
	static constexpr const char* Shoes		= "SHOES";
	static constexpr const char* Bicycles	= "BICYCLES";
	static constexpr const char* Skis		= "SKIS";
	static constexpr const char* Roller_Skis = "ROLLER_SKIS";
} product_type;


// наыхе уюпюйрепхярхйх опндсйрнб
struct product_characteristics {
	static constexpr const char* Firm = "FIRM";
	static constexpr const char* Color = "COLOR";
	static constexpr const char* Price = "PRICE";
	static constexpr const char* Created_At = "CREATED_AT";
	static constexpr const char* Updated_At = "UPDATED_AT";
	static constexpr const char* Description = "DESCRIPTION";
};


// днонкмхрекэмше уюпюйрепхярхйх насбх
struct shoes_characteristics : product_characteristics {
	static constexpr const char* Size = "SIZE";
	static constexpr const char* Material = "MATERIAL";
};


// днонкмхрекэмше уюпюйрепхярхйх бекняхоеднб
struct bicycles_characteristics : product_characteristics {
	static constexpr const char* Wheels_Size = "WHEELS_SIZE";
	static constexpr const char* Frame_Size = "FRAME_SIZE";
	static constexpr const char* Material = "MATERIAL";
};


// днонкмхрекэмше уюпюйрепхярхйх кшф
struct skis_characteristics : product_characteristics {
	static constexpr const char* Size = "SIZE";
	static constexpr const char* Skiing_Style = "SKIING_STYLE";
};


// днонкмхрекэмше уюпюйрепхярхйх кшфепнккепнб
struct roller_skis_characteristics : product_characteristics {
	static constexpr const char* Size = "SIZE";
	static constexpr const char* Skiing_Style = "SKIING_STYLE";
};


