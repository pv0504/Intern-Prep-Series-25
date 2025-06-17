# SQL Basics + Joins - Complete Learning Guide

## 🎯 What is SQL?

SQL (Structured Query Language) is the standard language for managing and manipulating relational databases. It allows you to retrieve, insert, update, and delete data from databases. SQL is essential for data analysis, backend development, and working with any data-driven application.

## 📚 Essential Concepts to Learn

### SQL Fundamentals
- **Database Structure**: Tables, rows, columns, primary keys, foreign keys
- **Data Types**: VARCHAR, INT, DATE, BOOLEAN, DECIMAL, etc.
- **Basic Queries**: SELECT, FROM, WHERE, ORDER BY, LIMIT
- **Filtering Data**: Comparison operators, LIKE, IN, BETWEEN
- **Aggregate Functions**: COUNT, SUM, AVG, MAX, MIN
- **Grouping**: GROUP BY, HAVING clauses

### Data Manipulation
- **INSERT**: Adding new records to tables
- **UPDATE**: Modifying existing records
- **DELETE**: Removing records from tables
- **CREATE TABLE**: Defining new table structures
- **ALTER TABLE**: Modifying table structure
- **DROP TABLE**: Deleting tables

### Joins (The Heart of SQL)
- **INNER JOIN**: Matching records from both tables
- **LEFT JOIN**: All records from left table + matching from right
- **RIGHT JOIN**: All records from right table + matching from left
- **FULL OUTER JOIN**: All records from both tables
- **CROSS JOIN**: Cartesian product of both tables
- **SELF JOIN**: Joining a table with itself

### Advanced Concepts
- **Subqueries**: Nested queries for complex operations
- **Window Functions**: ROW_NUMBER, RANK, LAG, LEAD
- **Common Table Expressions (CTEs)**: Temporary result sets
- **CASE Statements**: Conditional logic in SQL
- **String Functions**: CONCAT, SUBSTRING, UPPER, LOWER
- **Date Functions**: DATE_ADD, DATEDIFF, DATE_FORMAT

## 📖 Learning Resources

### Free Online Courses
- **SQLBolt** - Interactive SQL tutorial with hands-on exercises
- **W3Schools SQL Tutorial** - Comprehensive beginner-friendly guide
- **Khan Academy Intro to SQL** - Video-based learning with practice
- **Codecademy SQL Course** - Interactive coding environment
- **freeCodeCamp SQL Course** - Complete curriculum on YouTube
- **CS50's Introduction to Databases** - Harvard's database fundamentals

### Interactive Learning Platforms
- **SQLiteOnline** - Practice SQL directly in browser
- **DB Fiddle** - Test SQL queries with different database engines
- **SQL Zoo** - Interactive SQL tutorials with real datasets
- **HackerRank SQL** - Coding challenges to test your skills
- **LeetCode Database** - SQL problems for interview preparation
- **SQLPad** - Online SQL editor and sharing platform

### Books
- **"Learning SQL" by Alan Beaulieu** - Comprehensive beginner guide
- **"SQL in 10 Minutes, Sams Teach Yourself" by Ben Forta** - Quick reference
- **"SQL Cookbook" by Anthony Molinaro** - Problem-solving approach
- **"High Performance MySQL" by Baron Schwartz** - Advanced optimization
- **"The Definitive Guide to SQLite" by Mike Owens** - Lightweight database focus

### Documentation and References
- **MySQL Documentation** - Official MySQL reference
- **PostgreSQL Documentation** - Comprehensive PostgreSQL guide
- **SQLite Documentation** - Lightweight database documentation
- **SQL Server Documentation** - Microsoft SQL Server reference
- **Oracle SQL Documentation** - Enterprise database reference

### YouTube Channels
- **Programming with Mosh** - Clear SQL tutorials for beginners
- **Derek Banas** - Comprehensive SQL tutorial series
- **Edureka** - SQL fundamentals and advanced topics
- **TechWorld with Nana** - Database concepts and SQL
- **Ben Awad** - Practical SQL for developers

## 🛠️ Hands-On Tasks

### Setup: Creating Sample Database
First, let's create sample tables to work with throughout our exercises:

```sql
-- Create sample database schema
CREATE TABLE employees (
    employee_id INT PRIMARY KEY,
    first_name VARCHAR(50),
    last_name VARCHAR(50),
    email VARCHAR(100),
    department_id INT,
    salary DECIMAL(10,2),
    hire_date DATE,
    manager_id INT
);

CREATE TABLE departments (
    department_id INT PRIMARY KEY,
    department_name VARCHAR(50),
    location VARCHAR(50)
);

CREATE TABLE projects (
    project_id INT PRIMARY KEY,
    project_name VARCHAR(100),
    start_date DATE,
    end_date DATE,
    budget DECIMAL(12,2)
);

CREATE TABLE employee_projects (
    employee_id INT,
    project_id INT,
    role VARCHAR(50),
    hours_worked INT,
    PRIMARY KEY (employee_id, project_id)
);

-- Insert sample data
INSERT INTO departments VALUES
(1, 'Engineering', 'San Francisco'),
(2, 'Marketing', 'New York'),
(3, 'Sales', 'Chicago'),
(4, 'HR', 'Los Angeles'),
(5, 'Finance', 'Boston');

INSERT INTO employees VALUES
(101, 'John', 'Smith', 'john.smith@company.com', 1, 85000.00, '2020-01-15', NULL),
(102, 'Sarah', 'Johnson', 'sarah.johnson@company.com', 1, 75000.00, '2020-03-10', 101),
(103, 'Mike', 'Brown', 'mike.brown@company.com', 2, 65000.00, '2019-11-20', NULL),
(104, 'Emily', 'Davis', 'emily.davis@company.com', 2, 60000.00, '2021-02-14', 103),
(105, 'David', 'Wilson', 'david.wilson@company.com', 3, 70000.00, '2020-07-08', NULL),
(106, 'Lisa', 'Anderson', 'lisa.anderson@company.com', 3, 55000.00, '2021-05-22', 105),
(107, 'Robert', 'Taylor', 'robert.taylor@company.com', 4, 60000.00, '2019-09-12', NULL),
(108, 'Jennifer', 'Martinez', 'jennifer.martinez@company.com', 5, 80000.00, '2018-12-03', NULL);

INSERT INTO projects VALUES
(201, 'Website Redesign', '2021-01-01', '2021-06-30', 150000.00),
(202, 'Mobile App Development', '2021-03-15', '2021-12-31', 300000.00),
(203, 'Marketing Campaign Q2', '2021-04-01', '2021-06-30', 75000.00),
(204, 'Database Migration', '2021-02-01', '2021-05-31', 100000.00),
(205, 'Customer Portal', '2021-05-01', '2021-10-31', 200000.00);

INSERT INTO employee_projects VALUES
(101, 201, 'Project Manager', 120),
(102, 201, 'Developer', 150),
(101, 202, 'Technical Lead', 100),
(102, 202, 'Developer', 180),
(103, 203, 'Marketing Manager', 90),
(104, 203, 'Marketing Specialist', 110),
(105, 204, 'Database Admin', 140),
(108, 204, 'Financial Analyst', 60);
```

### Task 1: Basic SQL Queries
**Goal**: Master fundamental SQL operations

```sql
-- 1. Basic SELECT queries
-- Get all employees
SELECT * FROM employees;

-- Get specific columns
SELECT first_name, last_name, salary FROM employees;

-- Get unique departments
SELECT DISTINCT department_id FROM employees;

-- 2. Filtering with WHERE
-- Employees with salary > 70000
SELECT first_name, last_name, salary 
FROM employees 
WHERE salary > 70000;

-- Employees in Engineering department
SELECT first_name, last_name 
FROM employees 
WHERE department_id = 1;

-- Employees hired after 2020
SELECT first_name, last_name, hire_date 
FROM employees 
WHERE hire_date > '2020-01-01';

-- 3. Using LIKE for pattern matching
-- Employees whose first name starts with 'J'
SELECT first_name, last_name 
FROM employees 
WHERE first_name LIKE 'J%';

-- Employees with 'son' in their last name
SELECT first_name, last_name 
FROM employees 
WHERE last_name LIKE '%son%';

-- 4. Using IN and BETWEEN
-- Employees in specific departments
SELECT first_name, last_name, department_id 
FROM employees 
WHERE department_id IN (1, 2, 3);

-- Employees with salary between 60000 and 80000
SELECT first_name, last_name, salary 
FROM employees 
WHERE salary BETWEEN 60000 AND 80000;

-- 5. Sorting results
-- Employees ordered by salary (descending)
SELECT first_name, last_name, salary 
FROM employees 
ORDER BY salary DESC;

-- Employees ordered by department, then by salary
SELECT first_name, last_name, department_id, salary 
FROM employees 
ORDER BY department_id, salary DESC;

-- 6. Limiting results
-- Top 3 highest paid employees
SELECT first_name, last_name, salary 
FROM employees 
ORDER BY salary DESC 
LIMIT 3;
```

**Practice Exercises**:
1. Find all employees whose email contains 'company.com'
2. Get employees hired in 2020
3. Find employees with salary less than 70000, ordered by hire date
4. Get the first 5 employees alphabetically by last name

### Task 2: Aggregate Functions and Grouping
**Goal**: Learn to summarize and group data

```sql
-- 1. Basic aggregate functions
-- Total number of employees
SELECT COUNT(*) as total_employees FROM employees;

-- Average salary
SELECT AVG(salary) as average_salary FROM employees;

-- Highest and lowest salary
SELECT MAX(salary) as highest_salary, MIN(salary) as lowest_salary FROM employees;

-- Total salary expenses
SELECT SUM(salary) as total_salary_expense FROM employees;

-- 2. GROUP BY for departmental analysis
-- Number of employees per department
SELECT department_id, COUNT(*) as employee_count 
FROM employees 
GROUP BY department_id;

-- Average salary per department
SELECT department_id, AVG(salary) as avg_salary 
FROM employees 
GROUP BY department_id;

-- Salary statistics per department
SELECT 
    department_id,
    COUNT(*) as employee_count,
    AVG(salary) as avg_salary,
    MAX(salary) as max_salary,
    MIN(salary) as min_salary,
    SUM(salary) as total_salary
FROM employees 
GROUP BY department_id;

-- 3. HAVING clause for filtering groups
-- Departments with more than 1 employee
SELECT department_id, COUNT(*) as employee_count 
FROM employees 
GROUP BY department_id 
HAVING COUNT(*) > 1;

-- Departments with average salary > 65000
SELECT department_id, AVG(salary) as avg_salary 
FROM employees 
GROUP BY department_id 
HAVING AVG(salary) > 65000;

-- 4. Date functions and grouping
-- Employees hired per year
SELECT 
    YEAR(hire_date) as hire_year, 
    COUNT(*) as employees_hired 
FROM employees 
GROUP BY YEAR(hire_date);

-- Employees hired per month in 2020
SELECT 
    MONTH(hire_date) as hire_month, 
    COUNT(*) as employees_hired 
FROM employees 
WHERE YEAR(hire_date) = 2020
GROUP BY MONTH(hire_date);
```

**Practice Exercises**:
1. Find the total number of projects
2. Calculate the average project budget
3. Count how many projects end in 2021
4. Find departments with total salary expense > 150000

### Task 3: Introduction to Joins
**Goal**: Understand how to combine data from multiple tables

```sql
-- 1. INNER JOIN - Only matching records
-- Get employee names with their department names
SELECT 
    e.first_name, 
    e.last_name, 
    d.department_name
FROM employees e
INNER JOIN departments d ON e.department_id = d.department_id;

-- Employee details with department and location
SELECT 
    e.first_name, 
    e.last_name, 
    e.salary,
    d.department_name,
    d.location
FROM employees e
INNER JOIN departments d ON e.department_id = d.department_id;

-- 2. LEFT JOIN - All records from left table
-- All departments and their employees (including departments with no employees)
SELECT 
    d.department_name,
    e.first_name,
    e.last_name
FROM departments d
LEFT JOIN employees e ON d.department_id = e.department_id;

-- Count employees per department (including empty departments)
SELECT 
    d.department_name,
    COUNT(e.employee_id) as employee_count
FROM departments d
LEFT JOIN employees e ON d.department_id = e.department_id
GROUP BY d.department_id, d.department_name;

-- 3. Multiple table joins
-- Employee project assignments with all details
SELECT 
    e.first_name,
    e.last_name,
    p.project_name,
    ep.role,
    ep.hours_worked
FROM employees e
INNER JOIN employee_projects ep ON e.employee_id = ep.employee_id
INNER JOIN projects p ON ep.project_id = p.project_id;

-- 4. Self JOIN - Joining table with itself
-- Employees and their managers
SELECT 
    emp.first_name + ' ' + emp.last_name as employee_name,
    mgr.first_name + ' ' + mgr.last_name as manager_name
FROM employees emp
LEFT JOIN employees mgr ON emp.manager_id = mgr.employee_id;

-- 5. Complex joins with filtering
-- Engineering employees working on projects
SELECT 
    e.first_name,
    e.last_name,
    d.department_name,
    p.project_name,
    ep.hours_worked
FROM employees e
INNER JOIN departments d ON e.department_id = d.department_id
INNER JOIN employee_projects ep ON e.employee_id = ep.employee_id
INNER JOIN projects p ON ep.project_id = p.project_id
WHERE d.department_name = 'Engineering';
```

### Task 4: Advanced Joins and Relationships
**Goal**: Master complex join scenarios and data relationships

```sql
-- 1. FULL OUTER JOIN - All records from both tables
-- All employees and all departments (show unmatched records too)
SELECT 
    e.first_name,
    e.last_name,
    d.department_name
FROM employees e
FULL OUTER JOIN departments d ON e.department_id = d.department_id;

-- 2. CROSS JOIN - Cartesian product
-- All possible employee-project combinations (use carefully!)
SELECT 
    e.first_name,
    e.last_name,
    p.project_name
FROM employees e
CROSS JOIN projects p;

-- 3. Join with aggregations
-- Department summary with employee count and total salary
SELECT 
    d.department_name,
    d.location,
    COUNT(e.employee_id) as employee_count,
    COALESCE(SUM(e.salary), 0) as total_salary,
    COALESCE(AVG(e.salary), 0) as avg_salary
FROM departments d
LEFT JOIN employees e ON d.department_id = e.department_id
GROUP BY d.department_id, d.department_name, d.location;

-- 4. Project participation analysis
-- Projects with employee participation details
SELECT 
    p.project_name,
    p.budget,
    COUNT(ep.employee_id) as team_size,
    SUM(ep.hours_worked) as total_hours,
    AVG(ep.hours_worked) as avg_hours_per_person
FROM projects p
LEFT JOIN employee_projects ep ON p.project_id = ep.project_id
GROUP BY p.project_id, p.project_name, p.budget;

-- 5. Hierarchical data with self-joins
-- Manager hierarchy with employee counts
SELECT 
    mgr.first_name + ' ' + mgr.last_name as manager_name,
    mgr.salary as manager_salary,
    COUNT(emp.employee_id) as direct_reports,
    AVG(emp.salary) as avg_subordinate_salary
FROM employees mgr
LEFT JOIN employees emp ON mgr.employee_id = emp.manager_id
GROUP BY mgr.employee_id, mgr.first_name, mgr.last_name, mgr.salary;

-- 6. Complex business queries
-- Top performing employees (by project hours and salary)
SELECT 
    e.first_name,
    e.last_name,
    e.salary,
    d.department_name,
    SUM(ep.hours_worked) as total_project_hours,
    COUNT(ep.project_id) as projects_count,
    AVG(ep.hours_worked) as avg_hours_per_project
FROM employees e
INNER JOIN departments d ON e.department_id = d.department_id
LEFT JOIN employee_projects ep ON e.employee_id = ep.employee_id
GROUP BY e.employee_id, e.first_name, e.last_name, e.salary, d.department_name
ORDER BY total_project_hours DESC, e.salary DESC;

-- 7. Department efficiency analysis
-- Department performance metrics
SELECT 
    d.department_name,
    COUNT(DISTINCT e.employee_id) as employee_count,
    COUNT(DISTINCT ep.project_id) as projects_involved,
    SUM(ep.hours_worked) as total_project_hours,
    SUM(e.salary) as total_salary_cost,
    CASE 
        WHEN SUM(ep.hours_worked) > 0 
        THEN ROUND(SUM(e.salary) / SUM(ep.hours_worked), 2)
        ELSE 0 
    END as cost_per_hour
FROM departments d
LEFT JOIN employees e ON d.department_id = e.department_id
LEFT JOIN employee_projects ep ON e.employee_id = ep.employee_id
GROUP BY d.department_id, d.department_name
ORDER BY cost_per_hour;
```

### Task 5: Subqueries and Advanced Techniques
**Goal**: Learn complex querying techniques

```sql
-- 1. Simple subqueries
-- Employees earning above average salary
SELECT first_name, last_name, salary
FROM employees
WHERE salary > (SELECT AVG(salary) FROM employees);

-- Employees in the department with most employees
SELECT first_name, last_name, department_id
FROM employees
WHERE department_id = (
    SELECT department_id
    FROM employees
    GROUP BY department_id
    ORDER BY COUNT(*) DESC
    LIMIT 1
);

-- 2. Correlated subqueries
-- Employees earning above their department average
SELECT e1.first_name, e1.last_name, e1.salary, e1.department_id
FROM employees e1
WHERE e1.salary > (
    SELECT AVG(e2.salary)
    FROM employees e2
    WHERE e2.department_id = e1.department_id
);

-- 3. EXISTS and NOT EXISTS
-- Employees who are working on projects
SELECT first_name, last_name
FROM employees e
WHERE EXISTS (
    SELECT 1
    FROM employee_projects ep
    WHERE ep.employee_id = e.employee_id
);

-- Employees not assigned to any project
SELECT first_name, last_name
FROM employees e
WHERE NOT EXISTS (
    SELECT 1
    FROM employee_projects ep
    WHERE ep.employee_id = e.employee_id
);

-- 4. Common Table Expressions (CTEs)
-- Department salary rankings using CTE
WITH dept_salary_stats AS (
    SELECT 
        department_id,
        AVG(salary) as avg_salary,
        MAX(salary) as max_salary,
        COUNT(*) as employee_count
    FROM employees
    GROUP BY department_id
)
SELECT 
    d.department_name,
    dss.avg_salary,
    dss.max_salary,
    dss.employee_count
FROM dept_salary_stats dss
JOIN departments d ON dss.department_id = d.department_id
ORDER BY dss.avg_salary DESC;

-- 5. Window functions
-- Employee salary ranking within departments
SELECT 
    first_name,
    last_name,
    department_id,
    salary,
    ROW_NUMBER() OVER (PARTITION BY department_id ORDER BY salary DESC) as salary_rank,
    RANK() OVER (PARTITION BY department_id ORDER BY salary DESC) as salary_rank_with_ties
FROM employees;

-- Running total of salaries by department
SELECT 
    first_name,
    last_name,
    department_id,
    salary,
    SUM(salary) OVER (PARTITION BY department_id ORDER BY hire_date) as running_total
FROM employees
ORDER BY department_id, hire_date;

-- 6. CASE statements for conditional logic
-- Employee categorization based on salary
SELECT 
    first_name,
    last_name,
    salary,
    CASE 
        WHEN salary >= 80000 THEN 'High'
        WHEN salary >= 65000 THEN 'Medium'
        ELSE 'Low'
    END as salary_category,
    CASE 
        WHEN DATEDIFF(CURDATE(), hire_date) > 365 THEN 'Experienced'
        ELSE 'New'
    END as experience_level
FROM employees;
```

**Practice Challenges**:
1. Find employees who earn more than their manager
2. List departments that have no active projects
3. Calculate the percentage of total company salary each department represents
4. Find the employee with the most project hours in each department

## 📊 Join Types Visual Reference

### Understanding Join Types with Examples

```sql
-- Sample data for join examples
-- Table A (employees): [1,2,3,4]
-- Table B (departments): [2,3,4,5]

-- INNER JOIN: [2,3,4] - only matching records
SELECT * FROM employees e INNER JOIN departments d ON e.dept_id = d.dept_id;

-- LEFT JOIN: [1,2,3,4] - all from left + matching from right
SELECT * FROM employees e LEFT JOIN departments d ON e.dept_id = d.dept_id;

-- RIGHT JOIN: [2,3,4,5] - all from right + matching from left
SELECT * FROM employees e RIGHT JOIN departments d ON e.dept_id = d.dept_id;

-- FULL OUTER JOIN: [1,2,3,4,5] - all records from both tables
SELECT * FROM employees e FULL OUTER JOIN departments d ON e.dept_id = d.dept_id;
```

## 💡 Best Practices and Tips

### Query Optimization
- **Use indexes** on frequently joined columns
- **Select only needed columns** instead of SELECT *
- **Filter early** with WHERE clauses before joining
- **Use LIMIT** when you don't need all results
- **Avoid unnecessary GROUP BY** operations

### Writing Clean SQL
- **Use table aliases** for readability (e.g., `employees e`)
- **Indent and format** your queries consistently
- **Comment complex queries** to explain business logic
- **Use meaningful column aliases** in SELECT statements
- **Order clauses consistently**: SELECT, FROM, JOIN, WHERE, GROUP BY, HAVING, ORDER BY

### Common Pitfalls to Avoid
- **Cartesian products** from missing JOIN conditions
- **NULL handling** - remember NULL != NULL
- **Ambiguous column names** in multi-table queries
- **Mixing aggregate and non-aggregate columns** without GROUP BY
- **Using HAVING instead of WHERE** for non-aggregate filtering

### Performance Considerations
- **Understand your data** - table sizes, relationships, indexes
- **Use EXPLAIN** to analyze query execution plans
- **Consider query alternatives** - sometimes a subquery is faster than a join
- **Be careful with DISTINCT** - it can be resource-intensive
- **Use appropriate data types** for better performance

## 🚀 Next Steps and Advanced Topics

### Advanced SQL Features
- **Stored Procedures** - Reusable code blocks
- **Functions** - Custom calculations and transformations
- **Triggers** - Automatic actions on data changes
- **Views** - Virtual tables for complex queries
- **Indexes** - Performance optimization strategies

### Database-Specific Features
- **MySQL** - JSON functions, full-text search
- **PostgreSQL** - Arrays, JSONB, advanced analytics
- **SQL Server** - T-SQL extensions, analytics functions
- **Oracle** - Advanced analytical functions, partitioning
- **SQLite** - Lightweight database for applications

### Modern SQL Applications
- **Data Analytics** - Business intelligence and reporting
- **Data Engineering** - ETL processes and data pipelines
- **Web Development** - Backend data operations
- **Data Science** - Data extraction and preparation
- **Database Administration** - Maintenance and optimization

### Tools to Master
- **Database Management Systems** - MySQL, PostgreSQL, SQL Server
- **GUI Tools** - phpMyAdmin, pgAdmin, MySQL Workbench
- **Command Line Tools** - mysql, psql, sqlite3
- **Cloud Databases** - AWS RDS, Google Cloud SQL, Azure SQL
- **Analytics Tools** - Tableau, Power BI, Looker

### Real-World Practice
- **Kaggle Datasets** - Practice with real data
- **SQL Challenges** - LeetCode, HackerRank, SQLBolt
- **Open Source Projects** - Contribute to database projects
- **Personal Projects** - Build applications with databases
- **Certification** - MySQL, PostgreSQL, Microsoft SQL Server certifications

Remember: SQL is a skill that improves with practice. Start with simple queries and gradually work your way up to complex multi-table joins and analytical queries. The key is understanding your data relationships and thinking logically about how to combine information from different sources!
