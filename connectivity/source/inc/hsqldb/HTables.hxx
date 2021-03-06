/* -*- Mode: C++; tab-width: 4; indent-tabs-mode: nil; c-basic-offset: 4 -*- */
/*
 * This file is part of the LibreOffice project.
 *
 * This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this
 * file, You can obtain one at http://mozilla.org/MPL/2.0/.
 *
 * This file incorporates work covered by the following license notice:
 *
 *   Licensed to the Apache Software Foundation (ASF) under one or more
 *   contributor license agreements. See the NOTICE file distributed
 *   with this work for additional information regarding copyright
 *   ownership. The ASF licenses this file to you under the Apache
 *   License, Version 2.0 (the "License"); you may not use this file
 *   except in compliance with the License. You may obtain a copy of
 *   the License at http://www.apache.org/licenses/LICENSE-2.0 .
 */
#ifndef INCLUDED_CONNECTIVITY_SOURCE_INC_HSQLDB_HTABLES_HXX
#define INCLUDED_CONNECTIVITY_SOURCE_INC_HSQLDB_HTABLES_HXX

#include <connectivity/sdbcx/VCollection.hxx>
#include <com/sun/star/sdbc/XDatabaseMetaData.hpp>
namespace connectivity
{
    namespace hsqldb
    {
        class OTables : public sdbcx::OCollection
        {
            css::uno::Reference< css::sdbc::XDatabaseMetaData >       m_xMetaData;

        protected:
            virtual sdbcx::ObjectType createObject(const OUString& _rName) override;
            virtual void impl_refresh() throw(css::uno::RuntimeException) override;
            virtual css::uno::Reference< css::beans::XPropertySet > createDescriptor() override;
            virtual sdbcx::ObjectType appendObject( const OUString& _rForName, const css::uno::Reference< css::beans::XPropertySet >& descriptor ) override;
            virtual void dropObject(sal_Int32 _nPos, const OUString& _sElementName) override;

            void createTable( const css::uno::Reference< css::beans::XPropertySet >& descriptor );
            virtual OUString getNameForObject(const sdbcx::ObjectType& _xObject) override;
        public:
            OTables(const css::uno::Reference< css::sdbc::XDatabaseMetaData >& _rMetaData,::cppu::OWeakObject& _rParent, ::osl::Mutex& _rMutex,
                const TStringVector &_rVector) : sdbcx::OCollection(_rParent, true, _rMutex, _rVector)
                ,m_xMetaData(_rMetaData)
            {}

            // only the name is identical to ::cppu::OComponentHelper
            virtual void SAL_CALL disposing() override;

            // XDrop
            void appendNew(const OUString& _rsNewTable);
        };
    }
}
#endif // INCLUDED_CONNECTIVITY_SOURCE_INC_HSQLDB_HTABLES_HXX

/* vim:set shiftwidth=4 softtabstop=4 expandtab: */
