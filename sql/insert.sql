SHOW TABLES;

CREATE TABLE users (
    user_id INT PRIMARY KEY AUTO_INCREMENT,
    username VARCHAR(50) NOT NULL,
    email VARCHAR(100) UNIQUE,
    birthdate DATE,
    registration_date TIMESTAMP DEFAULT CURRENT_TIMESTAMP
);

DESC users;
SELECT * FROM users;

INSERT INTO users VALUES (1, 'user1', 'user2@example.com', '1985-03-22', '2023-09-17 10:00:00');
SELECT * FROM users;

INSERT INTO users (username, email, birthdate) VALUES ('user2', 'user1@example.com', '1990-01-15');
SELECT * FROM users;

INSERT INTO users (username, email) VALUES ('user3', 'user3@example.com');
SELECT * FROM users;

INSERT INTO users (username, email, registration_date) VALUES ('user4', 'user4@example.com', DEFAULT);
SELECT * FROM users;

-- INSERT INTO users (email) VALUES ('user5@example.com');

CREATE TABLE categories (
  id INT NOT NULL AUTO_INCREMENT,
  name VARCHAR(255) NOT NULL,
  PRIMARY KEY (id)
);
DESC categories;

CREATE TABLE products (
  id INT NOT NULL AUTO_INCREMENT,
  name VARCHAR(255) NOT NULL,
  category_id INT NOT NULL,
  PRIMARY KEY (id),
  FOREIGN KEY (category_id) REFERENCES categories (id)
);
DESC products;

INSERT INTO categories (name) VALUES ('전자제품');
INSERT INTO categories (name) VALUES ('의류');
SELECT * FROM categories;

INSERT INTO products (name, category_id) VALUES ('스마트폰', 1);
INSERT INTO products (name, category_id) VALUES ('노트북', 1);
INSERT INTO products (name, category_id) VALUES ('티셔츠', 2);
INSERT INTO products (name, category_id) VALUES ('청바지', 2);
SELECT * FROM products;
