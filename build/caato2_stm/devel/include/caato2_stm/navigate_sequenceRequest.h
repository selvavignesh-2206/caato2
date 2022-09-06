// Generated by gencpp from file caato2_stm/navigate_sequenceRequest.msg
// DO NOT EDIT!


#ifndef CAATO2_STM_MESSAGE_NAVIGATE_SEQUENCEREQUEST_H
#define CAATO2_STM_MESSAGE_NAVIGATE_SEQUENCEREQUEST_H


#include <string>
#include <vector>
#include <map>

#include <ros/types.h>
#include <ros/serialization.h>
#include <ros/builtin_message_traits.h>
#include <ros/message_operations.h>


namespace caato2_stm
{
template <class ContainerAllocator>
struct navigate_sequenceRequest_
{
  typedef navigate_sequenceRequest_<ContainerAllocator> Type;

  navigate_sequenceRequest_()
    : navigation_sequence_x()
    , navigation_sequence_y()
    , navigation_sequence_theta()  {
    }
  navigate_sequenceRequest_(const ContainerAllocator& _alloc)
    : navigation_sequence_x(_alloc)
    , navigation_sequence_y(_alloc)
    , navigation_sequence_theta(_alloc)  {
  (void)_alloc;
    }



   typedef std::vector<float, typename ContainerAllocator::template rebind<float>::other >  _navigation_sequence_x_type;
  _navigation_sequence_x_type navigation_sequence_x;

   typedef std::vector<float, typename ContainerAllocator::template rebind<float>::other >  _navigation_sequence_y_type;
  _navigation_sequence_y_type navigation_sequence_y;

   typedef std::vector<float, typename ContainerAllocator::template rebind<float>::other >  _navigation_sequence_theta_type;
  _navigation_sequence_theta_type navigation_sequence_theta;





  typedef boost::shared_ptr< ::caato2_stm::navigate_sequenceRequest_<ContainerAllocator> > Ptr;
  typedef boost::shared_ptr< ::caato2_stm::navigate_sequenceRequest_<ContainerAllocator> const> ConstPtr;

}; // struct navigate_sequenceRequest_

typedef ::caato2_stm::navigate_sequenceRequest_<std::allocator<void> > navigate_sequenceRequest;

typedef boost::shared_ptr< ::caato2_stm::navigate_sequenceRequest > navigate_sequenceRequestPtr;
typedef boost::shared_ptr< ::caato2_stm::navigate_sequenceRequest const> navigate_sequenceRequestConstPtr;

// constants requiring out of line definition



template<typename ContainerAllocator>
std::ostream& operator<<(std::ostream& s, const ::caato2_stm::navigate_sequenceRequest_<ContainerAllocator> & v)
{
ros::message_operations::Printer< ::caato2_stm::navigate_sequenceRequest_<ContainerAllocator> >::stream(s, "", v);
return s;
}


template<typename ContainerAllocator1, typename ContainerAllocator2>
bool operator==(const ::caato2_stm::navigate_sequenceRequest_<ContainerAllocator1> & lhs, const ::caato2_stm::navigate_sequenceRequest_<ContainerAllocator2> & rhs)
{
  return lhs.navigation_sequence_x == rhs.navigation_sequence_x &&
    lhs.navigation_sequence_y == rhs.navigation_sequence_y &&
    lhs.navigation_sequence_theta == rhs.navigation_sequence_theta;
}

template<typename ContainerAllocator1, typename ContainerAllocator2>
bool operator!=(const ::caato2_stm::navigate_sequenceRequest_<ContainerAllocator1> & lhs, const ::caato2_stm::navigate_sequenceRequest_<ContainerAllocator2> & rhs)
{
  return !(lhs == rhs);
}


} // namespace caato2_stm

namespace ros
{
namespace message_traits
{





template <class ContainerAllocator>
struct IsMessage< ::caato2_stm::navigate_sequenceRequest_<ContainerAllocator> >
  : TrueType
  { };

template <class ContainerAllocator>
struct IsMessage< ::caato2_stm::navigate_sequenceRequest_<ContainerAllocator> const>
  : TrueType
  { };

template <class ContainerAllocator>
struct IsFixedSize< ::caato2_stm::navigate_sequenceRequest_<ContainerAllocator> >
  : FalseType
  { };

template <class ContainerAllocator>
struct IsFixedSize< ::caato2_stm::navigate_sequenceRequest_<ContainerAllocator> const>
  : FalseType
  { };

template <class ContainerAllocator>
struct HasHeader< ::caato2_stm::navigate_sequenceRequest_<ContainerAllocator> >
  : FalseType
  { };

template <class ContainerAllocator>
struct HasHeader< ::caato2_stm::navigate_sequenceRequest_<ContainerAllocator> const>
  : FalseType
  { };


template<class ContainerAllocator>
struct MD5Sum< ::caato2_stm::navigate_sequenceRequest_<ContainerAllocator> >
{
  static const char* value()
  {
    return "501bc2b9f86a0e660a5f6064e8d01002";
  }

  static const char* value(const ::caato2_stm::navigate_sequenceRequest_<ContainerAllocator>&) { return value(); }
  static const uint64_t static_value1 = 0x501bc2b9f86a0e66ULL;
  static const uint64_t static_value2 = 0x0a5f6064e8d01002ULL;
};

template<class ContainerAllocator>
struct DataType< ::caato2_stm::navigate_sequenceRequest_<ContainerAllocator> >
{
  static const char* value()
  {
    return "caato2_stm/navigate_sequenceRequest";
  }

  static const char* value(const ::caato2_stm::navigate_sequenceRequest_<ContainerAllocator>&) { return value(); }
};

template<class ContainerAllocator>
struct Definition< ::caato2_stm::navigate_sequenceRequest_<ContainerAllocator> >
{
  static const char* value()
  {
    return "float32[] navigation_sequence_x\n"
"float32[] navigation_sequence_y\n"
"float32[] navigation_sequence_theta\n"
;
  }

  static const char* value(const ::caato2_stm::navigate_sequenceRequest_<ContainerAllocator>&) { return value(); }
};

} // namespace message_traits
} // namespace ros

namespace ros
{
namespace serialization
{

  template<class ContainerAllocator> struct Serializer< ::caato2_stm::navigate_sequenceRequest_<ContainerAllocator> >
  {
    template<typename Stream, typename T> inline static void allInOne(Stream& stream, T m)
    {
      stream.next(m.navigation_sequence_x);
      stream.next(m.navigation_sequence_y);
      stream.next(m.navigation_sequence_theta);
    }

    ROS_DECLARE_ALLINONE_SERIALIZER
  }; // struct navigate_sequenceRequest_

} // namespace serialization
} // namespace ros

namespace ros
{
namespace message_operations
{

template<class ContainerAllocator>
struct Printer< ::caato2_stm::navigate_sequenceRequest_<ContainerAllocator> >
{
  template<typename Stream> static void stream(Stream& s, const std::string& indent, const ::caato2_stm::navigate_sequenceRequest_<ContainerAllocator>& v)
  {
    s << indent << "navigation_sequence_x[]" << std::endl;
    for (size_t i = 0; i < v.navigation_sequence_x.size(); ++i)
    {
      s << indent << "  navigation_sequence_x[" << i << "]: ";
      Printer<float>::stream(s, indent + "  ", v.navigation_sequence_x[i]);
    }
    s << indent << "navigation_sequence_y[]" << std::endl;
    for (size_t i = 0; i < v.navigation_sequence_y.size(); ++i)
    {
      s << indent << "  navigation_sequence_y[" << i << "]: ";
      Printer<float>::stream(s, indent + "  ", v.navigation_sequence_y[i]);
    }
    s << indent << "navigation_sequence_theta[]" << std::endl;
    for (size_t i = 0; i < v.navigation_sequence_theta.size(); ++i)
    {
      s << indent << "  navigation_sequence_theta[" << i << "]: ";
      Printer<float>::stream(s, indent + "  ", v.navigation_sequence_theta[i]);
    }
  }
};

} // namespace message_operations
} // namespace ros

#endif // CAATO2_STM_MESSAGE_NAVIGATE_SEQUENCEREQUEST_H
