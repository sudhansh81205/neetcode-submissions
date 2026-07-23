-- Write your query below
SELECT sp.name FROM sales_person sp
WHERE sales_id NOT IN (
    SELECT DISTINCT(o.sales_id) FROM  orders o
    LEFT JOIN company c
    ON o.com_id = c.com_Id 
    WHERE c.name = 'CRIMSON'
);