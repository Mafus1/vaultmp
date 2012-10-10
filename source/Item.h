#ifndef ITEM_H
#define ITEM_H

#define TYPECLASS
#include "GameFactory.h"

#include "vaultmp.h"
#include "Data.h"
#include "Value.h"
#include "Object.h"

#ifdef VAULTSERVER
#include "vaultserver/Database.h"
#endif

#ifdef VAULTMP_DEBUG
#include "Debug.h"
#endif

class Container;

class Item : public Object
{
		friend class GameFactory;
		friend class Container;

	private:
#ifdef VAULTMP_DEBUG
		static DebugInput<Item> debug;
#endif

		Value<RakNet::NetworkID> item_Container;
		Value<unsigned int> item_Count;
		Value<double> item_Condition;
		Value<bool> state_Equipped;
		Value<bool> flag_Silent;
		Value<bool> flag_Stick;

		void initialize();

		Item(const Item&) = delete;
		Item& operator=(const Item&) = delete;

	protected:
		Item(unsigned int refID, unsigned int baseID);
		Item(const pDefault* packet);

	public:
		virtual ~Item();

		RakNet::NetworkID GetItemContainer() const;
		unsigned int GetItemCount() const;
		double GetItemCondition() const;
		bool GetItemEquipped() const;
		bool GetItemSilent() const;
		bool GetItemStick() const;

		Lockable* SetItemContainer(RakNet::NetworkID id);
		Lockable* SetItemCount(unsigned int count);
		Lockable* SetItemCondition(double condition);
		Lockable* SetItemEquipped(bool state);
		Lockable* SetItemSilent(bool silent);
		Lockable* SetItemStick(bool stick);

		RakNet::NetworkID Copy() const;

#ifdef VAULTSERVER
		/**
		 * \brief Sets the Item's base ID
		 */
		virtual Lockable* SetBase(unsigned int baseID);
#endif

		/**
		 * \brief For network transfer
		 */
		virtual pPacket toPacket() const;
};

#endif
