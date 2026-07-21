-- Write your query below
    SELECT student_id , exam_id , score FROM exam_results e
    WHERE score = (
        SELECT MAX(score) FROM exam_results 
        WHERE student_id = e.student_id 
    )
    AND exam_id =(
        SELECT MIN(exam_id) FROM exam_results 
        WHERE student_id = e.student_id 
        AND score = (
        SELECT MAX(score) FROM exam_results 
        WHERE student_id = e.student_id 
    )
    )
    ORDER BY student_id;

--   SELECT student_id, exam_id, score
-- FROM (
--     SELECT *,
--            ROW_NUMBER() OVER (
--                PARTITION BY student_id
--                ORDER BY score DESC, exam_id ASC
--            ) AS rn
--     FROM exam_results
-- ) t
-- WHERE rn = 1
-- ORDER BY student_id;