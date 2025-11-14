UPDATE dishes
SET price = price*1.1
FROM categories
WHERE dishes.category_id = categories.category_id AND categories.category_name = 'Супы';