#pragma once
#include "Joueur.h"
#include "Joueur_autonome.h"
#include "Joueur_non_autonome.h"
#include <boost/archive/text_oarchive.hpp>
#include <boost/archive/text_iarchive.hpp>
#include <boost/serialization/export.hpp>

BOOST_CLASS_EXPORT(Joueur);
BOOST_CLASS_EXPORT(Joueur_autonome);
BOOST_CLASS_EXPORT(Joueur_non_autonome);