SELECT * FROM dishes
JOIN categories ON dishes.category_id = categories.category_id
WHERE categories.category_name = 'Супы';