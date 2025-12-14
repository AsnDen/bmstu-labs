SELECT * FROM students s
WHERE s.student_id BETWEEN 4 - 2 AND 4 + 3 AND s.student_id <> 4
ORDER BY s.student_id