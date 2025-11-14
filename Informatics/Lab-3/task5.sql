SELECT categories.category_name, SUM(orders.total_price) AS profit
FROM categories, dishes, orders
WHERE orders.dish_id = dishes.id AND dishes.category_id = categories.category_id
GROUP BY categories.category_name
ORDER BY profit DESC;