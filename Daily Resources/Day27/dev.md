# Aggregates + Grouping + Window Functions: Complete Learning Guide

## What You'll Learn

### Aggregate Functions
- **Basic Aggregates**: COUNT, SUM, AVG, MIN, MAX
- **Advanced Aggregates**: STRING_AGG, ARRAY_AGG, statistical functions
- **Conditional Aggregates**: Using CASE with aggregates
- **NULL Handling**: How aggregates treat NULL values

### Grouping Operations
- **GROUP BY Fundamentals**: Single and multiple column grouping
- **HAVING Clause**: Filtering grouped results
- **GROUP BY Extensions**: ROLLUP, CUBE, GROUPING SETS
- **Grouping with Complex Expressions**: Functions and calculations in GROUP BY

### Window Functions
- **Ranking Functions**: ROW_NUMBER(), RANK(), DENSE_RANK(), NTILE()
- **Aggregate Window Functions**: SUM(), COUNT(), AVG() with OVER clause
- **Analytical Functions**: LAG(), LEAD(), FIRST_VALUE(), LAST_VALUE()
- **Window Frames**: ROWS vs RANGE, UNBOUNDED, CURRENT ROW
- **Partitioning**: PARTITION BY for grouped calculations

### Advanced Concepts
- **Multiple Window Functions**: Combining different window functions
- **Window Functions vs GROUP BY**: When to use which approach
- **Performance Optimization**: Indexing strategies for grouped queries
- **Complex Analytics**: Percentiles, moving averages, cumulative distributions

## Learning Path

### 1. Foundation (Start Here)
- Master basic SELECT statements and filtering
- Understand aggregate functions with simple datasets
- Learn GROUP BY syntax and behavior

### 2. Aggregate Mastery
- **Basic Aggregates**: COUNT, SUM, AVG, MIN, MAX with real data
- **Conditional Logic**: CASE statements within aggregates
- **Multiple Aggregates**: Combining different functions in one query
- **NULL Behavior**: Understanding how aggregates handle missing data

### 3. Grouping Techniques
- **Single Column Grouping**: Basic GROUP BY operations
- **Multi-Column Grouping**: Complex grouping scenarios
- **HAVING Clause**: Filtering after aggregation
- **Advanced Grouping**: ROLLUP, CUBE for subtotals and cross-tabs

### 4. Window Functions Deep Dive
- **Ranking Functions**: Understanding different ranking behaviors
- **Partitioned Analytics**: Calculations within groups
- **Window Frames**: Controlling the scope of calculations
- **Advanced Analytics**: Moving averages, running totals, percentiles

### 5. Integration and Optimization
- **Combining Techniques**: Aggregates with window functions
- **Performance Tuning**: Query optimization strategies
- **Real-world Applications**: Business intelligence and reporting

## Learning Resources

### Online Tutorials
- **PostgreSQL Window Functions Tutorial**: Comprehensive guide with examples
- **W3Schools SQL Functions**: Basic aggregate functions with interactive examples
- **Mode Analytics SQL Tutorial**: Advanced analytics focus with real datasets
- **SQLShack**: In-depth articles on window functions and grouping

### Practice Platforms
- **SQLZoo**: Interactive window functions exercises
- **HackerRank SQL Domain**: Aggregation and advanced select challenges
- **LeetCode Database**: Window function problems with varying difficulty
- **DataCamp SQL Courses**: Hands-on practice with real datasets

### Video Resources
- **YouTube - Zach Star**: Visual explanations of window functions
- **YouTube - Alex The Analyst**: Practical SQL analytics tutorials
- **Coursera - SQL for Data Science**: University-level courses with projects
- **LinkedIn Learning**: Professional SQL courses for business analytics

### Documentation & References
- **PostgreSQL Window Functions Documentation**: Most comprehensive resource
- **MySQL Window Functions Reference**: Version 8.0+ features
- **SQL Server Windowing Functions**: Microsoft's implementation guide
- **Oracle Analytic Functions Guide**: Advanced enterprise features

### Books & Deep Learning
- **"Learning SQL" by Alan Beaulieu**: Comprehensive coverage of all topics
- **"SQL Cookbook" by Anthony Molinaro**: Practical recipes for complex queries
- **"The Art of SQL" by Stéphane Faroult**: Performance and design principles

## Hands-On Tasks

### Task 1: Sales Performance Dashboard
**Scenario**: You're analyzing sales data for a retail company with multiple stores, products, and salespeople.

**Your Mission**:
1. **Basic Aggregates**: Create monthly sales summaries by store and product category
2. **Advanced Grouping**: Use ROLLUP to show sales totals with subtotals by region, store, and overall
3. **Window Functions**: Calculate each salesperson's rank within their store and running total of their sales
4. **Complex Analytics**: Find the top 3 products by sales in each category, and calculate month-over-month growth rates

**Sample Tables Structure**:
```sql
-- Create practice tables
CREATE TABLE stores (store_id, store_name, region, city);
CREATE TABLE products (product_id, name, category, price);
CREATE TABLE salespeople (salesperson_id, name, store_id, hire_date);
CREATE TABLE sales (
    sale_id, salesperson_id, product_id, quantity, 
    sale_date, discount_percent
);
```

**Skills Practiced**: 
- Multiple aggregates (COUNT, SUM, AVG)
- GROUP BY with ROLLUP
- ROW_NUMBER() and RANK() window functions
- LAG() for period-over-period calculations
- PARTITION BY for grouped rankings

### Task 2: Customer Behavior Analysis
**Scenario**: E-commerce platform needs to understand customer purchasing patterns and lifecycle analytics.

**Your Mission**:
1. **Customer Segmentation**: Group customers by purchase frequency and calculate average order values
2. **Cohort Analysis**: Use window functions to track customer retention by registration month
3. **Advanced Window Functions**: Calculate each customer's:
   - Days between purchases (LAG function)
   - Lifetime value running total
   - Percentile ranking by total spending
   - First and last purchase dates within each year
4. **Statistical Analysis**: Find customers whose spending is above the 75th percentile in their region

**Sample Tables Structure**:
```sql
-- Create practice tables
CREATE TABLE customers (
    customer_id, name, email, registration_date, 
    region, age_group
);
CREATE TABLE orders (
    order_id, customer_id, order_date, total_amount, 
    payment_method, status
);
CREATE TABLE order_items (
    order_item_id, order_id, product_id, 
    quantity, unit_price
);
```

**Skills Practiced**:
- Complex GROUP BY with HAVING clauses
- Multiple window functions in single queries
- NTILE() for percentile calculations
- FIRST_VALUE() and LAST_VALUE() with proper window frames
- LAG() and LEAD() for sequential analysis
- Combining aggregates with window functions

## Tips for Success

### Best Practices
- **Start Simple**: Master basic aggregates before moving to complex window functions
- **Understand NULL Behavior**: Know how each function handles missing data
- **Use Proper Window Frames**: Specify ROWS vs RANGE explicitly
- **Optimize Performance**: Consider indexing strategies for grouped queries

### Common Pitfalls to Avoid
- **Mixing Aggregates and Non-Aggregates**: Remember GROUP BY rules
- **Window Frame Confusion**: Default frames can give unexpected results
- **Performance Issues**: Large window operations can be slow
- **NULL Surprises**: Understand how NULLs affect different functions

### Debugging Strategies
- **Test Incrementally**: Build complex queries step by step
- **Use Small Datasets**: Debug logic before scaling up
- **Verify Window Frames**: Use ORDER BY to check frame boundaries
- **Check Edge Cases**: Test with NULLs, duplicates, and empty sets

### Performance Tips
- **Index Strategy**: Create indexes on GROUP BY and PARTITION BY columns
- **Limit Window Scope**: Use appropriate PARTITION BY to reduce calculation scope
- **Avoid Unnecessary Sorting**: Window functions can be expensive with large datasets
- **Consider Alternatives**: Sometimes subqueries or CTEs are more efficient

## Quick Reference

### Aggregate Functions
```sql
-- Basic aggregates
SELECT COUNT(*), SUM(amount), AVG(amount), MIN(date), MAX(date)
FROM sales GROUP BY region;

-- Conditional aggregates
SELECT 
    SUM(CASE WHEN status = 'completed' THEN amount ELSE 0 END) as completed_sales,
    COUNT(CASE WHEN status = 'pending' THEN 1 END) as pending_orders
FROM orders GROUP BY region;

-- Advanced grouping
SELECT region, store, SUM(sales)
FROM sales_data
GROUP BY ROLLUP(region, store);
```

### Window Functions
```sql
-- Ranking functions
SELECT 
    name, salary,
    ROW_NUMBER() OVER (ORDER BY salary DESC) as row_num,
    RANK() OVER (ORDER BY salary DESC) as rank,
    DENSE_RANK() OVER (ORDER BY salary DESC) as dense_rank
FROM employees;

-- Partitioned window functions
SELECT 
    department, name, salary,
    AVG(salary) OVER (PARTITION BY department) as dept_avg,
    SUM(salary) OVER (PARTITION BY department ORDER BY hire_date 
                     ROWS UNBOUNDED PRECEDING) as running_total
FROM employees;

-- Analytical functions
SELECT 
    date, sales,
    LAG(sales, 1) OVER (ORDER BY date) as prev_month_sales,
    LEAD(sales, 1) OVER (ORDER BY date) as next_month_sales,
    FIRST_VALUE(sales) OVER (ORDER BY date ROWS UNBOUNDED PRECEDING) as first_sale,
    LAST_VALUE(sales) OVER (ORDER BY date ROWS BETWEEN UNBOUNDED PRECEDING 
                            AND UNBOUNDED FOLLOWING) as last_sale
FROM monthly_sales;
```

### Window Frame Syntax
```sql
-- Different frame types
ROWS BETWEEN UNBOUNDED PRECEDING AND CURRENT ROW  -- All previous rows + current
ROWS BETWEEN 2 PRECEDING AND 2 FOLLOWING          -- 5-row sliding window
RANGE BETWEEN INTERVAL '1' MONTH PRECEDING AND CURRENT ROW  -- Time-based window
```

## Key Formulas & Patterns

### Moving Averages
```sql
SELECT date, value,
    AVG(value) OVER (ORDER BY date ROWS BETWEEN 2 PRECEDING AND CURRENT ROW) as ma_3
FROM time_series;
```

### Percentiles
```sql
SELECT name, score,
    NTILE(4) OVER (ORDER BY score) as quartile,
    PERCENT_RANK() OVER (ORDER BY score) as percentile_rank
FROM test_scores;
```

### Running Totals
```sql
SELECT date, amount,
    SUM(amount) OVER (ORDER BY date ROWS UNBOUNDED PRECEDING) as running_total
FROM transactions;
```

Master these concepts and you'll be able to handle complex analytical queries with confidence!
