#pragma once

#include <string>

// ГЛАВНЫЕ МЕТОДЫ
enum METHODS { Get, Post, Put, Delete, Login ,Logout};


// Наименования столбцов таблицы БД "Users" + имя таблицы
struct users_struct {
	static constexpr std::string_view table_name 	= "Users";
	static constexpr std::string_view id 		 	= "id";
	static constexpr std::string_view first_name 	= "first_name";
	static constexpr std::string_view last_name  	= "last_name";
	static constexpr std::string_view email		 	= "email";
	static constexpr std::string_view password_hash	= "password_hash";
	static constexpr std::string_view role			= "role";
} const inline users;


// Наименования столбцов таблицы БД "Products" + имя таблицы
struct products_struct {
	static constexpr std::string_view table_name 	= "Products";
	static constexpr std::string_view id 		 	= "id";
	static constexpr std::string_view name 		 	= "name";
	static constexpr std::string_view price 	 	= "price";
	static constexpr std::string_view description 	= "description";
	static constexpr std::string_view images 	 	= "images";
	static constexpr std::string_view category_id 	= "category_id";
} const inline products;


// Наименования столбцов таблицы БД "Categories" + имя таблицы 
struct categories_struct {
	static constexpr std::string_view table_name 	= "Categories";
	static constexpr std::string_view id 		 	= "id";
	static constexpr std::string_view name 		 	= "name";
} const inline categories;


// Наименования столбцов таблицы БД "Orders" + имя таблицы 
struct orders_struct {
	static constexpr std::string_view table_name 	= "Orders";
	static constexpr std::string_view id 		 	= "id";
	static constexpr std::string_view user_id	 	= "user_id";
	static constexpr std::string_view status	 	= "status";
	static constexpr std::string_view created_at 	= "created_at";
	static constexpr std::string_view updated_at 	= "updated_at";
} const inline orders;


// Наименования столбцов таблицы БД "Reviews" + имя таблицы 
struct reviews_struct {
	static constexpr std::string_view table_name 	= "Reviews";
	static constexpr std::string_view id 		 	= "id";
	static constexpr std::string_view user_id	 	= "user_id";
	static constexpr std::string_view product_id 	= "product_id";
	static constexpr std::string_view rating	 	= "rating";
	static constexpr std::string_view comment	 	= "comment";
} const inline reviews;


// Наименования столбцов таблицы БД "Carts" + имя таблицы 
struct carts_struct {
	static constexpr std::string_view table_name 	= "Carts";
	static constexpr std::string_view id 		 	= "id";
	static constexpr std::string_view user_id	 	= "user_id";
	static constexpr std::string_view product_id 	= "product_id";
	static constexpr std::string_view quantity	 	= "quantity";
} const inline carts;


// Наименования столбцов таблицы БД "Order_items" + имя таблицы 
struct order_items_struct {
	static constexpr std::string_view table_name 	= "Order_items";
	static constexpr std::string_view id 		 	= "id";
	static constexpr std::string_view product_id 	= "product_id";
	static constexpr std::string_view order_id	 	= "order_id";
	static constexpr std::string_view quantity	 	= "quantity";
	static constexpr std::string_view price		 	= "price";
} const inline order_items;