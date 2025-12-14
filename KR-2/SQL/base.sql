CREATE TABLE students (
    student_id SERIAL PRIMARY KEY,
    full_name TEXT NOT NULL,
    group_number INT CHECK (group_number > 0) NOT NULL
);

CREATE TABLE subjects (
    subject_id SERIAL PRIMARY KEY,
    subject_name TEXT NOT NULL
);

CREATE TABLE grades (
    grade_id SERIAL PRIMARY KEY,
    student_id INT NOT NULL REFERENCES students(student_id),
    subject_id INT NOT NULL REFERENCES subjects(subject_id),
    grade INT NOT NULL CHECK (grade BETWEEN 0 AND 100)
);

CREATE TABLE attendance (
    attendance_id SERIAL PRIMARY KEY,
    student_id INT NOT NULL REFERENCES students(student_id),
    date_attended DATE NOT NULL,
    status VARCHAR(10) CHECK (status IN ('present', 'absent', 'late'))
);

CREATE TABLE notes (
    note_id SERIAL PRIMARY KEY,
    student_id INT NOT NULL REFERENCES students(student_id),
    note_text TEXT
);

INSERT INTO students (full_name, group_number) VALUES
	('Alica Lubimova', 1),
	('Petr Perzovski', 1),
	('Zaur Magamedav', 1),
	('Rusalina Valieva', 1),
	('Denis Novikov', 1),
	('Alex Radukin', 1);

INSERT INTO subjects (subject_name) VALUES
	('Math analysis'),
	('Analytical geometry'),
	('Informatics');

INSERT INTO grades (student_id, subject_id, grade) VALUES
	(1, 1, 85), (1, 2, 87), (1, 3, 100),
	(2, 1, 52), (2, 2, 67), (2, 3, 83),
	(3, 1, 0),  (3, 2, 30), (3, 3, 85),
	(4, 1, 100),(4, 2, 78), (4, 3, 87),
	(5, 1, 45), (5, 2, 90), (5, 3, 99),
	(6, 1, 10), (6, 2, 82), (6, 3, 79);

INSERT INTO attendance (student_id, date_attended, status) VALUES
	(1, '2025-12-12', 'present'),
	(1, '2025-12-13', 'present'),
	(2, '2025-12-12', 'present'),
	(2, '2025-12-13', 'present'),
	(3, '2025-12-12', 'late'),
	(3, '2025-12-13', 'late'),
	(4, '2025-12-12', 'late'),
	(4, '2025-12-13', 'late'),
	(5, '2025-12-12', 'late'),
	(5, '2025-12-13', 'late'),
	(6, '2025-12-12', 'absent'),
	(6, '2025-12-13', 'late');

INSERT INTO notes (student_id, note_text) VALUES
	(1, 'Loves eating food'),
	(2, 'Loves sleeping'),
	(3, 'Thinks he never late'),
	(4, 'She is cooler that Zaur'),
	(5, 'Alive deepseek of group');

CREATE INDEX idx_group_number ON students(group_number);
CREATE INDEX idx_grades_student ON grades(student_id);
CREATE INDEX idx_notes_text ON notes
USING GIN (to_tsvector('english', note_text));

CREATE VIEW student_avg_grades AS
SELECT
    s.student_id,
    s.full_name,
    AVG(g.grade) AS avg_grade
FROM students s
JOIN grades g ON s.student_id = g.student_id
GROUP BY s.student_id, s.full_name;

BEGIN;

WITH new_student AS (
    INSERT INTO students (full_name, group_number)
    VALUES ('Egor Cuz', 1)
    RETURNING student_id
)
INSERT INTO grades (student_id, subject_id, grade)
SELECT student_id, subject_id, grade
FROM new_student
CROSS JOIN (VALUES
    (1, 50),
    (2, 100),
    (3, 23)
) AS g(subject_id, grade);

COMMIT;
