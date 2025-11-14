DELETE FROM orders
USING dishes
WHERE orders.dish_id = dishes.id AND dishes.name = 'Цезарь';

DELETE FROM dishes
WHERE dishes.name = 'Цезарь'
