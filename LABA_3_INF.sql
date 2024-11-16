--#1
--SELECT * FROM dishes
--where category_id = 3

--#2
--SELECT * FROM orders
--where order_date = '27/03/2006'

--#3
--SELECT SUM(total_price) AS total from orders where order_date = '27/03/2006'

--#4
SELECT 
    dishes.name AS dish_name,
    SUM(orders.quantity) AS total_quantity
FROM 
    orders
JOIN 
    dishes ON dishes.id = orders.dish_id
GROUP BY 
    dishes.name
ORDER BY 
    total_quantity DESC
LIMIT 1;