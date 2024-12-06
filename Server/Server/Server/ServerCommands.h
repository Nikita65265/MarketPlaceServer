#pragma once

#include <string>

// ������� ������
enum class METHODS { Get, Post, Put, Delete, Login ,Logout};

// ��������� ������ HTTP
struct http_response_struct {
	// ������ ���������
	static constexpr std::string_view http_version  = "HTTP_VERSION";
	static constexpr std::string_view status_code   = "STATUS_CODE";
	static constexpr std::string_view status_phrase = "STATUS_PHRASE";

	// ���������
	static constexpr std::string_view content_type   = "CONTENT_TYPE";
	static constexpr std::string_view charset		 = "CHARSET";
	static constexpr std::string_view content_length = "CONTENT_LENGTH";
	static constexpr std::string_view server_name    = "SERVER_NAME";
	static constexpr std::string_view date		     = "DATE";

	// ���� ������
	static constexpr std::string_view body = "BODY";
} const inline http_response;


// ��������� ������� HTTP
struct http_request_struct {
	// ������ �������
	static constexpr std::string_view method	   = "METHOD";
	static constexpr std::string_view uri		   = "URI";
	static constexpr std::string_view http_version = "HTTP_VERSION";

	// ���������
	static constexpr std::string_view host			 = "HOST";
	static constexpr std::string_view user			 = "USER";
	static constexpr std::string_view accept		 = "ACCEPT";
	static constexpr std::string_view content_type   = "CONTENT_TYPE";
	static constexpr std::string_view content_length = "CONTENT_LENGTH";

	// ���� �������
	static constexpr std::string_view body = "BODY";
};


// ������������ �������� ������� �� "Users" + ��� �������
struct users_struct {
	static constexpr std::string_view table_name 	= "Users";
	static constexpr std::string_view id 		 	= "id";
	static constexpr std::string_view first_name 	= "first_name";
	static constexpr std::string_view last_name  	= "last_name";
	static constexpr std::string_view email		 	= "email";
	static constexpr std::string_view password_hash	= "password_hash";
	static constexpr std::string_view role			= "role";
} const inline users;


// ������������ �������� ������� �� "Products" + ��� �������
struct products_struct {
	static constexpr std::string_view table_name 	= "Products";
	static constexpr std::string_view id 		 	= "id";
	static constexpr std::string_view name 		 	= "name";
	static constexpr std::string_view price 	 	= "price";
	static constexpr std::string_view description 	= "description";
	static constexpr std::string_view images 	 	= "images";
	static constexpr std::string_view category_id 	= "category_id";
} const inline products;


// ������������ �������� ������� �� "Categories" + ��� ������� 
struct categories_struct {
	static constexpr std::string_view table_name 	= "Categories";
	static constexpr std::string_view id 		 	= "id";
	static constexpr std::string_view name 		 	= "name";
} const inline categories;


// ������������ �������� ������� �� "Orders" + ��� ������� 
struct orders_struct {
	static constexpr std::string_view table_name 	= "Orders";
	static constexpr std::string_view id 		 	= "id";
	static constexpr std::string_view user_id	 	= "user_id";
	static constexpr std::string_view status	 	= "status";
	static constexpr std::string_view created_at 	= "created_at";
	static constexpr std::string_view updated_at 	= "updated_at";
} const inline orders;


// ������������ �������� ������� �� "Reviews" + ��� ������� 
struct reviews_struct {
	static constexpr std::string_view table_name 	= "Reviews";
	static constexpr std::string_view id 		 	= "id";
	static constexpr std::string_view user_id	 	= "user_id";
	static constexpr std::string_view product_id 	= "product_id";
	static constexpr std::string_view rating	 	= "rating";
	static constexpr std::string_view comment	 	= "comment";
} const inline reviews;


// ������������ �������� ������� �� "Carts" + ��� ������� 
struct carts_struct {
	static constexpr std::string_view table_name 	= "Carts";
	static constexpr std::string_view id 		 	= "id";
	static constexpr std::string_view user_id	 	= "user_id";
	static constexpr std::string_view product_id 	= "product_id";
	static constexpr std::string_view quantity	 	= "quantity";
} const inline carts;


// ������������ �������� ������� �� "Order_items" + ��� ������� 
struct order_items_struct {
	static constexpr std::string_view table_name 	= "Order_items";
	static constexpr std::string_view id 		 	= "id";
	static constexpr std::string_view product_id 	= "product_id";
	static constexpr std::string_view order_id	 	= "order_id";
	static constexpr std::string_view quantity	 	= "quantity";
	static constexpr std::string_view price		 	= "price";
} const inline order_items;