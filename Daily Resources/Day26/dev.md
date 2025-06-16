# Subqueries + CTEs: Complete Learning Guide

## What You'll Learn

### Subqueries
- **Definition**: Queries nested inside other queries
- **Types**: Scalar, row, table, and correlated subqueries
- **Use Cases**: Filtering, calculations, existence checks
- **Performance Considerations**: When to use vs alternatives

### Common Table Expressions (CTEs)
- **Definition**: Named temporary result sets within a query
- **Syntax**: WITH clause fundamentals
- **Types**: Simple CTEs, recursive CTEs
- **Benefits**: Code readability, reusability, complex logic breakdown

### Advanced Concepts
- **Multiple CTEs**: Chaining and referencing
- **Subqueries vs CTEs**: When to use which approach
- **Performance Optimization**: Execution plans and best practices
- **Real-world Applications**: Hierarchical data, running totals, data analysis

## Learning Path

### 1. Foundation (Start Here)
- Understand basic SELECT statements and JOINs
- Learn subquery syntax and placement (WHERE, SELECT, FROM clauses)
- Practice simple filtering with subqueries

### 2. Subquery Mastery
- **Scalar Subqueries**: Return single values
- **Row Subqueries**: Return single rows
- **Table Subqueries**: Return multiple rows/columns
- **Correlated Subqueries**: Reference outer query columns
- **EXISTS/NOT EXISTS**: Efficient existence checking

### 3. CTE Fundamentals
- **Basic WITH Clause**: Creating named result sets
- **Multiple CTEs**: Building complex logic step by step
- **CTE vs Subquery**: Understanding when each is appropriate

### 4. Advanced Techniques
- **Recursive CTEs**: Hierarchical and tree-like data
- **Window Functions with CTEs**: Advanced analytics
- **Performance Optimization**: Query execution plans

## Learning Resources

### Online Tutorials
- **W3Schools SQL Tutorial**: Great for beginners, covers subqueries and CTEs
- **SQLBolt**: Interactive exercises with immediate feedback
- **Mode Analytics SQL Tutorial**: Real-world examples and best practices
- **PostgreSQL Documentation**: Comprehensive CTE and subquery reference

### Practice Platforms
- **HackerRank SQL Domain**: Structured problems from basic to advanced
- **LeetCode Database Problems**: Interview-style SQL challenges
- **SQLZoo**: Interactive tutorials with instant results
- **DB Fiddle**: Online SQL playground for testing queries

### Video Resources
- **YouTube - Programming with Mosh**: SQL subqueries explained clearly
- **YouTube - Kudvenkat**: Detailed CTE tutorials with examples
- **Pluralsight/Udemy**: Comprehensive SQL courses covering advanced topics

### Documentation
- **MySQL Reference Manual**: Subqueries and CTEs section
- **PostgreSQL Documentation**: WITH queries (CTEs) chapter
- **SQL Server Documentation**: Common table expressions guide
- **Oracle Database Concepts**: Subqueries and WITH clause

## Hands-On Tasks

### Task 1: E-commerce Analytics
**Scenario**: You have an e-commerce database with customers, orders, and products tables.

**Your Mission**:
1. **Using Subqueries**: Find customers who have spent more than the average order amount
2. **Using CTEs**: Create a sales report showing:
   - Monthly sales totals
   - Running total of sales
   - Percentage of each month compared to total annual sales

**Sample Tables Structure**:
```sql
-- Create practice tables
CREATE TABLE customers (customer_id, name, email, registration_date);
CREATE TABLE orders (order_id, customer_id, order_date, total_amount);
CREATE TABLE order_items (order_id, product_id, quantity, price);
CREATE TABLE products (product_id, name, category, price);
```

**Skills Practiced**: Scalar subqueries, aggregate functions, window functions with CTEs, data analysis

### Task 2: Employee Hierarchy Analysis
**Scenario**: Company database with employee hierarchy and department structure.

**Your Mission**:
1. **Using Recursive CTEs**: Build a complete organizational chart showing all employees under each manager
2. **Using Correlated Subqueries**: Find departments where the average salary is above the company average
3. **Combining Both**: Create a report showing each employee's position in hierarchy and how their salary compares to their level average

**Sample Tables Structure**:
```sql
-- Create practice tables
CREATE TABLE employees (employee_id, name, manager_id, department_id, salary, hire_date);
CREATE TABLE departments (department_id, name, location);
```

**Skills Practiced**: Recursive CTEs, correlated subqueries, hierarchical data, complex analytics

## Tips for Success

### Best Practices
- **Start Simple**: Begin with basic subqueries before moving to complex CTEs
- **Use Proper Formatting**: Indent nested queries and CTEs for readability
- **Test Incrementally**: Build complex queries step by step
- **Check Performance**: Use EXPLAIN plans to understand query execution

### Common Pitfalls to Avoid
- **Overusing Correlated Subqueries**: Can be performance-heavy
- **Deep Nesting**: Makes queries hard to read and maintain
- **Ignoring NULL Values**: Always consider NULL handling in subqueries
- **Recursive CTE Infinite Loops**: Always include proper termination conditions

### Debugging Strategies
- **Isolate Subqueries**: Test them independently first
- **Use Small Datasets**: Debug with limited data before scaling up
- **Add Comments**: Document complex logic for future reference
- **Version Control**: Save working versions before making changes

## Quick Reference

### Subquery Syntax
```sql
-- WHERE clause subquery
SELECT * FROM table1 WHERE column1 IN (SELECT column2 FROM table2);

-- SELECT clause subquery
SELECT column1, (SELECT MAX(column2) FROM table2) FROM table1;

-- FROM clause subquery
SELECT * FROM (SELECT column1, COUNT(*) FROM table1 GROUP BY column1) AS subquery;
```

### CTE Syntax
```sql
-- Basic CTE
WITH cte_name AS (
    SELECT column1, column2 FROM table1 WHERE condition
)
SELECT * FROM cte_name;

-- Multiple CTEs
WITH cte1 AS (...), cte2 AS (...)
SELECT * FROM cte1 JOIN cte2 ON condition;

-- Recursive CTE
WITH RECURSIVE cte_name AS (
    -- Base case
    SELECT columns FROM table WHERE condition
    UNION ALL
    -- Recursive case
    SELECT columns FROM table JOIN cte_name ON condition
)
SELECT * FROM cte_name;
```

Remember: The goal is to write clean, readable, and efficient SQL. Both subqueries and CTEs are powerful tools - choose the right one for each situation!
