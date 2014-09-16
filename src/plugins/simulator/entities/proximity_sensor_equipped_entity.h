/**
 * @file <argos3/plugins/simulator/entities/proximity_sensor_equipped_entity.h>
 *
 * @author Carlo Pinciroli - <ilpincy@gmail.com>
 */

#ifndef PROXIMITY_SENSOR_EQUIPPED_ENTITY_H
#define PROXIMITY_SENSOR_EQUIPPED_ENTITY_H

namespace argos {
   class CProximitySensorEquippedEntity;
}

#include <argos3/core/utility/math/vector3.h>
#include <argos3/core/simulator/entity/entity.h>
#include <argos3/core/simulator/entity/embodied_entity.h>
#include <map>

namespace argos {

   class CProximitySensorEquippedEntity : public CEntity {

   public:

      ENABLE_VTABLE();

      struct SSensor {
         typedef std::vector<SSensor*> TList;

         CVector3 Offset;
         CVector3 Direction;
         const CEmbodiedEntity::SAnchor& Anchor;

         SSensor(const CVector3& c_offset,
                 const CVector3& c_direction,
                 Real f_range,
                 const CEmbodiedEntity::SAnchor& s_anchor);
      };

   public:

      CProximitySensorEquippedEntity(CComposableEntity* pc_parent);

      CProximitySensorEquippedEntity(CComposableEntity* pc_parent,
                                     const std::string& str_id);

      virtual ~CProximitySensorEquippedEntity();

      virtual void Init(TConfigurationNode& t_tree);

      virtual std::string GetTypeDescription() const {
         return "proximity_sensors";
      }

      inline size_t GetNumSensors() const {
         return m_tSensors.size();
      }

      inline SSensor& GetSensor(size_t un_idx) {
         return *m_tSensors[un_idx];
      }

      inline SSensor::TList& GetSensors() {
         return m_tSensors;
      }

      void AddSensor(const CVector3& c_offset,
                     const CVector3& c_direction,
                     Real f_range,
                     const CEmbodiedEntity::SAnchor& s_anchor);

      void AddSensorRing(const CVector3& c_center,
                         Real f_radius,
                         const CRadians& c_start_angle,
                         Real f_range,
                         UInt32 un_num_sensors,
                         const CEmbodiedEntity::SAnchor& s_anchor);

   protected:

      /** The list of sensors */
      SSensor::TList m_tSensors;

   };

}

#endif
