CREATE TABLE categories (
	category_id INT PRIMARY KEY,
	category_name TEXT NOT NULL UNIQUE
);

CREATE TABLE dishes (
	id INT PRIMARY KEY,
	name TEXT NOT NULL UNIQUE,
	category_id INT NOT NULL REFERENCES categories(category_id),
	price DECIMAL(10,2) NOT NULL
);

CREATE TABLE orders (
	order_id INT PRIMARY KEY,
	dish_id INT NOT NULL REFERENCES dishes(id),
	order_date DATE NOT NULL,
	quantity INT NOT NULL,
	total_price DECIMAL(30,2) NOT NULL
);