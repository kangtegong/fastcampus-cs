SHOW DATABASES;
CREATE DATABASE example;
UES example;
SHOW databases;

CREATE TABLE categories (
  id INT NOT NULL AUTO_INCREMENT,
  name VARCHAR(255) NOT NULL,
  PRIMARY KEY (id)
);

CREATE TABLE products (
  id INT NOT NULL AUTO_INCREMENT,
  name VARCHAR(255) NOT NULL,
  category_id INT NOT NULL,
  price INT NOT NULL,
  registration_date TIMESTAMP NOT NULL,
  PRIMARY KEY (id),
  FOREIGN KEY (category_id) REFERENCES categories (id)
);

show tables;
DESC categories;
DESC products;

INSERT INTO categories (name) VALUES
  ('Category 1'),
  ('Category 2'),
  ('Category 3'),
  ('Category 4'),
  ('Category 5'),
  ('Category 6'),
  ('Category 7'),
  ('Category 8'),
  ('Category 9'),
  ('Category 10');

SELECT * FROM categories;

INSERT INTO products (name, category_id, price, registration_date) VALUES
  ('apple', 1, 1000, '2023-09-20 10:00:00'),
  ('banana', 2, 800, '2023-09-20 11:30:00'),
  ('keyboard', 3, 1200, '2023-09-20 12:45:00'),
  ('monitor', 3, 1500, '2023-09-20 14:20:00'),
  ('small monitor', 2, 750, '2023-09-20 15:10:00'),
  ('big monitor', 4, 2000, '2023-09-20 16:40:00'),
  ('headphone', 3, 1350, '2023-09-20 18:00:00'),
  ('pizza', 1, 950, '2023-09-20 19:30:00'),
  ('chicken', 1, 1800, '2023-09-20 21:15:00'),
  ('glasses', 2, 1000, '2023-09-20 22:45:00');

SELECT * FROM products;


-- 특정 카테고리 이름 변경
UPDATE categories
SET name = 'Category Test'
WHERE id = 1;
SELECT * FROM categories;

-- 특정 제품 가격 변경
UPDATE products
SET price = 1000
WHERE name = 'keyboard';
SELECT * FROM products;

-- 특정 제품의 등록 날짜 변경:
UPDATE products
SET registration_date = '2023-09-21 08:00:00'
WHERE name = 'banana';

-- 가격 1000 이상인 모든 제품 가격을 10% 할인
UPDATE products
SET price = price * 0.9
WHERE price >= 1000;

-- 특정 날짜 이전에 등록된 모든 제품의 카테고리를 변경:
UPDATE products
SET price = price * 0.95
WHERE registration_date < '2023-09-20 15:00:00';



CREATE TABLE customers (
    customer_id INT PRIMARY KEY,
    customer_name VARCHAR(255) NOT NULL
);

INSERT INTO customers (customer_id, customer_name)
VALUES
    (1, '고객1'),
    (2, '고객2'),
    (3, '고객3');

-- orders 테이블 생성
CREATE TABLE orders (
    order_id INT PRIMARY KEY,
    order_customer_id INT,
    order_total DECIMAL(10, 2),
    CONSTRAINT fk_order_customer
    FOREIGN KEY (order_customer_id) REFERENCES customers(customer_id)
    ON UPDATE CASCADE
    -- ON UPDATE SET NULL
    -- ON UPDATE SET DEFAULT
    --  ON UPDATE RESTRICT
    -- ON UPDATE NO ACTION
);

INSERT INTO orders (order_id, order_customer_id, order_total)
VALUES
    (101, 1, 100.00),
    (102, 2, 50.00),
    (103, 3, 75.00);

DESC orders;
DESC customers;
SELECT * FROM orders;
SELECT * FROM customers;

UPDATE customers SET customer_id = 4 WHERE customer_id = 1;

SELECT * FROM customers;
SELECT * FROM orders;

ALTER TABLE orders DROP FOREIGN KEY fk_order_customer;

ALTER TABLE orders
    ADD CONSTRAINT fk_order_customer
    FOREIGN KEY (order_customer_id) REFERENCES customers(customer_id)
    ON UPDATE SET NULL;

SELECT * FROM customers;
SELECT * FROM orders;

UPDATE customers SET customer_id = 10 WHERE customer_id = 2;

ALTER TABLE orders DROP FOREIGN KEY fk_order_customer;
ALTER TABLE orders
    ADD CONSTRAINT fk_order_customer
    FOREIGN KEY (order_customer_id) REFERENCES customers(customer_id)
    ON UPDATE RESTRICT;

UPDATE customers SET customer_id = 40 WHERE customer_id = 3;

