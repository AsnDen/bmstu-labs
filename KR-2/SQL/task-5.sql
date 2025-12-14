BEGIN;

UPDATE attendance
SET status = 'late'
WHERE student_id = 2 AND date_attended = '2025-12-13';

COMMIT;