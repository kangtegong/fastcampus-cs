SHOW DATABASES;
CREATE DATABASE example;
USE example;
SHOW databases;

CREATE TABLE customers (
    customer_id INT PRIMARY KEY,
    customer_name VARCHAR(255) NOT NULL
);

INSERT INTO customers (customer_id, customer_name)
VALUES
    (1, '고객1'),
    (2, '고객2'),
    (3, '고객3'),
    (4, '고객4'),
    (5, '고객5'),
    (6, '고객6')
    ;

SELECT * FROM customers;    
    
DELETE FROM customers;
SELECT * FROM customers;    

DELETE FROM customers WHERE customer_id = 1;
DELETE FROM customers WHERE customer_name = '고객3';
DELETE FROM customers WHERE customer_name LIKE '고객%' AND customer_id < 5;

CREATE TABLE orders (
    order_id INT PRIMARY KEY,
    order_customer_id INT,
    order_total DECIMAL(10, 2),
    CONSTRAINT fk_order_customer
    FOREIGN KEY (order_customer_id) REFERENCES customers(customer_id)
    ON DELETE CASCADE 
    -- ON DELETE SET NULL
    -- ON DELETE SET DEFAULT
    --  ON DELETE RESTRICT
    -- ON DELETE NO ACTION
);


INSERT INTO orders (order_id, order_customer_id, order_total)
VALUES
    (101, 1, 100.00),
    (102, 2, 50.00),
    (103, 3, 75.00),
    (104, 4, 175.00),
    (105, 5, 275.00);

DESC orders;
DESC customers;
SELECT * FROM orders;
SELECT * FROM customers;

DELETE FROM customers WHERE customer_id = 2;

SELECT * FROM customers;
SELECT * FROM orders;

ALTER TABLE orders DROP FOREIGN KEY fk_order_customer;

ALTER TABLE orders
    ADD CONSTRAINT fk_order_customer
    FOREIGN KEY (order_customer_id) REFERENCES customers(customer_id)
    ON DELETE SET NULL;

SELECT * FROM customers;
SELECT * FROM orders;

DELETE FROM customers WHERE customer_id = 3;

ALTER TABLE orders DROP FOREIGN KEY fk_order_customer;

ALTER TABLE orders
    ADD CONSTRAINT fk_order_customer
    FOREIGN KEY (order_customer_id) REFERENCES customers(customer_id)
    ON DELETE RESTRICT;

DELETE FROM customers WHERE customer_id = 4;

