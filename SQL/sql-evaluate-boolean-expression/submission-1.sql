select 
    e.left_operand,
    e.operator,
    e.right_operand,
    CASE
        WHEN e.operator = '>' AND v1.value > v2.value THEN 'true'
        WHEN e.operator = '<' AND v1.value < v2.value THEN 'true'
        WHEN e.operator = '=' AND v1.value = v2.value THEN 'true'
        ELSE 'false'
    END AS value
 from expressions as e
join variables v1
on e.left_operand = v1.name
join variables v2
on e.right_operand = v2.name
