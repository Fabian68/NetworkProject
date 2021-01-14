#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "../test/doctest.h"
#include "Simulation.h"

TEST_CASE("Un Hexagon ce construit correctement") {
	Simulation S();
	Point P(5.0, 5.0);
	Hexagon H(P, 5.0);

	SUBCASE("Le placement des points sont correct") {
		REQUIRE(H.getUp().getX() == 5.0);
		REQUIRE(H[0].getY() == 10.0);
		double degréePrecision = 0.0001;
		REQUIRE(H[1].getX() == doctest::Approx(9.33).epsilon(degréePrecision));
		REQUIRE(H[1].getY() == doctest::Approx(7.5).epsilon(degréePrecision));

		REQUIRE(H[2].getX() == doctest::Approx(9.33).epsilon(degréePrecision));
		REQUIRE(H[2].getY() == doctest::Approx(2.5).epsilon(degréePrecision));

		REQUIRE(H[3].getX() == doctest::Approx(5.0).epsilon(degréePrecision));
		REQUIRE(H[3].getY() == doctest::Approx(0.0).epsilon(degréePrecision));

		REQUIRE(H[4].getX() == doctest::Approx(0.67).epsilon(degréePrecision));
		REQUIRE(H[4].getY() == doctest::Approx(2.5).epsilon(degréePrecision));

		REQUIRE(H[5].getX() == doctest::Approx(0.67).epsilon(degréePrecision));
		REQUIRE(H[5].getY() == doctest::Approx(7.5).epsilon(degréePrecision));
	}
	SUBCASE("Le test de contient un point est correct") {
		
		SUBCASE("TEST DE LA PARTIE HAUTE") {
			Point exterieur(2.0, 9.0);
			Point interieur(4.0, 9.0);

			Point exterieur2(8.0, 9.0);
			Point interieur2(6.0, 9.0);

			REQUIRE(H.contains(exterieur) == false);
			REQUIRE(H.contains(interieur) == true);

			REQUIRE(H.contains(exterieur2) == false);
			REQUIRE(H.contains(interieur2) == true);
		}
		SUBCASE("TEST DE LA PARTIE BASSE") {
			Point exterieur(2.0, 1.0);
			Point interieur(4.0, 1.0);

			Point exterieur2(8.0, 1.0);
			Point interieur2(6.0, 1.0);

			REQUIRE(H.contains(exterieur) == false);
			REQUIRE(H.contains(interieur) == true);

			REQUIRE(H.contains(exterieur2) == false);
			REQUIRE(H.contains(interieur2) == true);
		}
		SUBCASE("TEST DE LA PARTIE MILIEU ET GENERAL") {
			Point exterieur(0.1, 6.0);
			Point interieur(5.0, 6.0);

			Point exterieur2(9.8, 4.0);
			Point interieur2(6.0, 5.0);

			Point exterieur3(4.0, -1.0);
			Point exterieur4(6.0, 11.0);
			REQUIRE(H.contains(exterieur) == false);
			REQUIRE(H.contains(interieur) == true);

			REQUIRE(H.contains(exterieur2) == false);
			REQUIRE(H.contains(interieur2) == true);

			REQUIRE(H.contains(exterieur3) == false);
			REQUIRE(H.contains(exterieur4) == false);
		}
	}
}

TEST_CASE("Une ligne d'hexagone ce construit correctement") {

	Point P(5.0, 5.0);
	
	int size = 10000;
	MeshLines M(P, 5.0, size);

	SUBCASE("Le placement des pointsdu premier hexagone sont  correct") {
		REQUIRE(M[0].getUp().getX() == 5.0);
		REQUIRE(M[0][0].getY() == 10.0);
		double degréePrecision = 0.0001;
		REQUIRE(M[0][1].getX() == doctest::Approx(9.33).epsilon(degréePrecision));
		REQUIRE(M[0][1].getY() == doctest::Approx(7.5).epsilon(degréePrecision));

		REQUIRE(M[0][2].getX() == doctest::Approx(9.33).epsilon(degréePrecision));
		REQUIRE(M[0][2].getY() == doctest::Approx(2.5).epsilon(degréePrecision));

		REQUIRE(M[0][3].getX() == doctest::Approx(5.0).epsilon(degréePrecision));
		REQUIRE(M[0][3].getY() == doctest::Approx(0.0).epsilon(degréePrecision));

		REQUIRE(M[0][4].getX() == doctest::Approx(0.67).epsilon(degréePrecision));
		REQUIRE(M[0][4].getY() == doctest::Approx(2.5).epsilon(degréePrecision));

		REQUIRE(M[0][5].getX() == doctest::Approx(0.67).epsilon(degréePrecision));
		REQUIRE(M[0][5].getY() == doctest::Approx(7.5).epsilon(degréePrecision));
	}

	SUBCASE("Chaque hexagone a deux points en commun") {
		SUBCASE("Test du premier et second hexagone") {
			REQUIRE(M[0].getUpRight().getX() == doctest::Approx(M[1].getUpLeft().getX()));
			REQUIRE(M[0].getUpRight().getY() == doctest::Approx(M[1].getUpLeft().getY()));

			REQUIRE(M[0].getDownRight().getX() == doctest::Approx(M[1].getDownLeft().getX()));
			REQUIRE(M[0].getDownRight().getY() == doctest::Approx(M[1].getDownLeft().getY()));
		}
		SUBCASE("Test du second et troisième hexagone") {
			REQUIRE(M[1].getUpRight().getX() == doctest::Approx(M[2].getUpLeft().getX()));
			REQUIRE(M[1].getUpRight().getY() == doctest::Approx(M[2].getUpLeft().getY()));

			REQUIRE(M[1].getDownRight().getX() == doctest::Approx(M[2].getDownLeft().getX()));
			REQUIRE(M[1].getDownRight().getY() == doctest::Approx(M[2].getDownLeft().getY()));
		}
		SUBCASE("Test des derniers hexagone( imprecision )") {
			REQUIRE(M[size-2].getUpRight().getX() == doctest::Approx(M[size - 1].getUpLeft().getX()));
			REQUIRE(M[size - 2].getUpRight().getY() == doctest::Approx(M[size - 1].getUpLeft().getY()));

			REQUIRE(M[size - 2].getDownRight().getX() == doctest::Approx(M[size - 1].getDownLeft().getX()));
			REQUIRE(M[size - 2].getDownRight().getY() == doctest::Approx(M[size - 1].getDownLeft().getY()));
		}
	}
}

TEST_CASE("Un pavage ce construit correctement") {


	Mesh M(Point(5.0, 5.0), 5.0, 3, 3);

	SUBCASE("Les lignes se surperposent correctement") {

			REQUIRE(M[0][0].getUp().getX() == doctest::Approx(M[1][0].getDownLeft().getX()));
			REQUIRE(M[0][0].getUp().getY() == doctest::Approx(M[1][0].getDownLeft().getY()));

			REQUIRE(M[0][0].getUpRight().getX() == doctest::Approx(M[0][1].getUpLeft().getX()));
			REQUIRE(M[0][0].getUpRight().getY() == doctest::Approx(M[0][1].getUpLeft().getY()));

			REQUIRE(M[1][0].getUpRight().getX() == doctest::Approx(M[2][1].getDown().getX()));
			REQUIRE(M[1][0].getUpRight().getY() == doctest::Approx(M[2][1].getDown().getY()));
	
	}
}