/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   types.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/08 23:36:57 by marvin            #+#    #+#             */
/*   Updated: 2025/04/08 23:36:57 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_TYPES_H
# define FT_TYPES_H

// ───────────────────────────────
//  SIGNED TYPES
// ───────────────────────────────

# ifndef TYPE_SIGNED
#  define TYPE_SIGNED		"signed"
# endif

# ifndef TYPE_INT
#  define TYPE_INT			"int"
# endif

# ifndef TYPE_LONG
#  define TYPE_LONG			"long"
# endif

# ifndef TYPE_LLONG
#  define TYPE_LLONG		"long long"
# endif

# ifndef TYPE_INT64
#  define TYPE_INT64		"int64"
# endif

// ───────────────────────────────
//  UNSIGNED TYPES
// ───────────────────────────────

# ifndef TYPE_UNSIGNED
#  define TYPE_UNSIGNED			"unsigned"
# endif

# ifndef TYPE_UINT
#  define TYPE_UINT			"unsigned int"
# endif

# ifndef TYPE_ULONG
#  define TYPE_ULONG		"unsigned long"
# endif

# ifndef TYPE_ULLONG
#  define TYPE_ULLONG		"unsigned long long"
# endif

# ifndef TYPE_UINT64
#  define TYPE_UINT64		"uint64"
# endif

// ───────────────────────────────
//  FOALTING-POINT TYPES
// ───────────────────────────────

# ifndef TYPE_FLOAT
#  define TYPE_FLOAT			"float"
# endif

# ifndef TYPE_DOUBLE
#  define TYPE_DOUBLE		"double"
# endif

# ifndef TYPE_LONGDOUBLE
#  define TYPE_LONGDOUBLE	"long double"
# endif

# ifndef FT_DBL_MAX
#  define FT_DBL_MAX		1.7976931348623157e+308
# endif

# ifndef FT_DBL_MIN
#  define FT_DBL_MIN			2.2250738585072014e-308
# endif

# ifndef FT_FLT_MAX
#  define FT_FLT_MAX			3.402823466e+38F
# endif

# ifndef FT_FLT_TRUE_MIN
#  define FT_FLT_TRUE_MIN	1.401298464324817e-45F
# endif

#endif