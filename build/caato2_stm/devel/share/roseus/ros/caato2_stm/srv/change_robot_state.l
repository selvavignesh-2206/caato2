;; Auto-generated. Do not edit!


(when (boundp 'caato2_stm::change_robot_state)
  (if (not (find-package "CAATO2_STM"))
    (make-package "CAATO2_STM"))
  (shadow 'change_robot_state (find-package "CAATO2_STM")))
(unless (find-package "CAATO2_STM::CHANGE_ROBOT_STATE")
  (make-package "CAATO2_STM::CHANGE_ROBOT_STATE"))
(unless (find-package "CAATO2_STM::CHANGE_ROBOT_STATEREQUEST")
  (make-package "CAATO2_STM::CHANGE_ROBOT_STATEREQUEST"))
(unless (find-package "CAATO2_STM::CHANGE_ROBOT_STATERESPONSE")
  (make-package "CAATO2_STM::CHANGE_ROBOT_STATERESPONSE"))

(in-package "ROS")





(defclass caato2_stm::change_robot_stateRequest
  :super ros::object
  :slots (_request_state_code ))

(defmethod caato2_stm::change_robot_stateRequest
  (:init
   (&key
    ((:request_state_code __request_state_code) 0)
    )
   (send-super :init)
   (setq _request_state_code (round __request_state_code))
   self)
  (:request_state_code
   (&optional __request_state_code)
   (if __request_state_code (setq _request_state_code __request_state_code)) _request_state_code)
  (:serialization-length
   ()
   (+
    ;; uint8 _request_state_code
    1
    ))
  (:serialize
   (&optional strm)
   (let ((s (if strm strm
              (make-string-output-stream (send self :serialization-length)))))
     ;; uint8 _request_state_code
       (write-byte _request_state_code s)
     ;;
     (if (null strm) (get-output-stream-string s))))
  (:deserialize
   (buf &optional (ptr- 0))
   ;; uint8 _request_state_code
     (setq _request_state_code (sys::peek buf ptr- :char)) (incf ptr- 1)
   ;;
   self)
  )

(defclass caato2_stm::change_robot_stateResponse
  :super ros::object
  :slots (_result ))

(defmethod caato2_stm::change_robot_stateResponse
  (:init
   (&key
    ((:result __result) nil)
    )
   (send-super :init)
   (setq _result __result)
   self)
  (:result
   (&optional (__result :null))
   (if (not (eq __result :null)) (setq _result __result)) _result)
  (:serialization-length
   ()
   (+
    ;; bool _result
    1
    ))
  (:serialize
   (&optional strm)
   (let ((s (if strm strm
              (make-string-output-stream (send self :serialization-length)))))
     ;; bool _result
       (if _result (write-byte -1 s) (write-byte 0 s))
     ;;
     (if (null strm) (get-output-stream-string s))))
  (:deserialize
   (buf &optional (ptr- 0))
   ;; bool _result
     (setq _result (not (= 0 (sys::peek buf ptr- :char)))) (incf ptr- 1)
   ;;
   self)
  )

(defclass caato2_stm::change_robot_state
  :super ros::object
  :slots ())

(setf (get caato2_stm::change_robot_state :md5sum-) "e0f1a708bebd365f6904a06dc2d07250")
(setf (get caato2_stm::change_robot_state :datatype-) "caato2_stm/change_robot_state")
(setf (get caato2_stm::change_robot_state :request) caato2_stm::change_robot_stateRequest)
(setf (get caato2_stm::change_robot_state :response) caato2_stm::change_robot_stateResponse)

(defmethod caato2_stm::change_robot_stateRequest
  (:response () (instance caato2_stm::change_robot_stateResponse :init)))

(setf (get caato2_stm::change_robot_stateRequest :md5sum-) "e0f1a708bebd365f6904a06dc2d07250")
(setf (get caato2_stm::change_robot_stateRequest :datatype-) "caato2_stm/change_robot_stateRequest")
(setf (get caato2_stm::change_robot_stateRequest :definition-)
      "uint8 request_state_code
---
bool result
")

(setf (get caato2_stm::change_robot_stateResponse :md5sum-) "e0f1a708bebd365f6904a06dc2d07250")
(setf (get caato2_stm::change_robot_stateResponse :datatype-) "caato2_stm/change_robot_stateResponse")
(setf (get caato2_stm::change_robot_stateResponse :definition-)
      "uint8 request_state_code
---
bool result
")



(provide :caato2_stm/change_robot_state "e0f1a708bebd365f6904a06dc2d07250")


